from tkinter import filedialog, messagebox
import datetime
from app.core.player import Player
from app.core.validators import PlayerValidator
from app.models.repository import PlayerRepository
from app.models.xml_serializer import XMLSerializer
from app.views.main_window import MainWindow
from app.views.dialogs import AddDialog, SearchDialog, DeleteDialog


class PlayerController:

    def __init__(self) -> None:
        self.model: PlayerRepository | None = None
        self.view: MainWindow | None = None
        self._current_dialog: AddDialog | None = None

    def set_model(self, model: PlayerRepository) -> None:
        self.model = model
        self.model.add_listener(self.sync_data_to_view)

    def set_view(self, view: MainWindow) -> None:
        self.view = view

    def sync_data_to_view(self) -> None:
        if self.view and self.model:
            self.view.table_view.set_data(self.model.all_players)

    def open_add_dialog(self) -> None:
        if self.view:
            self._current_dialog = AddDialog(self.view, self.add_player_callback)

    def add_player_callback(self, fio: str, birth_date: datetime.date, team: str, city: str, squad: str, position: str) -> None:
        error_msg = PlayerValidator.get_validation_error(fio, city, birth_date)
        if error_msg:
            messagebox.showerror("Ошибка валидации", error_msg)
            return

        player = Player(fio, birth_date, team, city, squad, position)
        if self.model:
            self.model.add_player(player)

        if self._current_dialog:
            self._current_dialog.destroy()
            self._current_dialog = None

    def open_search_dialog(self) -> None:
        if self.view:
            SearchDialog(self.view, self.search_callback)

    def search_callback(self, criteria: dict[str, object], strict: bool) -> list[Player] | None:
        error_msg = PlayerValidator.validate_search_criteria(criteria)
        if error_msg:
            messagebox.showerror("Ошибка валидации критериев", error_msg)
            return None

        if self.model:
            return self.model.filter_players(criteria, strict)
        return []

    def open_delete_dialog(self) -> None:
        if self.view:
            DeleteDialog(self.view, self.delete_callback)

    def delete_callback(self, criteria: dict[str, object], strict: bool) -> int | None:
        error_msg = PlayerValidator.validate_search_criteria(criteria)
        if error_msg:
            messagebox.showerror("Ошибка валидации критериев", error_msg)
            return None

        if self.model:
            return self.model.delete_players(criteria, strict)
        return 0

    def load_file(self) -> None:
        filepath = filedialog.askopenfilename(
            title="Открыть базу данных игроков XML", filetypes=[("XML Files", "*.xml")]
        )
        if filepath and self.model:
            try:
                players = XMLSerializer.read_players(filepath)
                self.model.all_players = players
                messagebox.showinfo("Успех", "Файл успешно прочитан с помощью SAX парсера!")
            except Exception as e:
                messagebox.showerror("Ошибка", f"Ошибка чтения файла:\n{str(e)}")

    def save_file(self) -> None:
        filepath = filedialog.asksaveasfilename(
            title="Сохранить базу данных игроков XML", defaultextension=".xml", filetypes=[("XML Files", "*.xml")]
        )
        if filepath and self.model:
            try:
                XMLSerializer.write_players(filepath, self.model.all_players)
                messagebox.showinfo("Успех", "Файл успешно сохранен с помощью DOM парсера!")
            except Exception as e:
                messagebox.showerror("Ошибка", f"Ошибка сохранения файла:\n{str(e)}")