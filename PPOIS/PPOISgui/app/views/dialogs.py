import tkinter as tk
from tkinter import ttk, messagebox
import datetime
from app.views.components import DateInputWidget, PaginatedTableView
from app.core.player import Player


class AddDialog(tk.Toplevel):

    def __init__(self, parent, callback) -> None:
        super().__init__(parent)
        self.title("Добавление игрока")
        self.geometry("420x320")
        self.callback = callback
        self.transient(parent)
        self.grab_set()

        frame = ttk.Frame(self, padding=15)
        frame.pack(fill=tk.BOTH, expand=True)

        ttk.Label(frame, text="ФИО игрока:").grid(row=0, column=0, sticky=tk.W, pady=5)
        self.ent_fio = ttk.Entry(frame, width=25)
        self.ent_fio.grid(row=0, column=1, pady=5, sticky=tk.W)

        ttk.Label(frame, text="Дата рождения:").grid(row=1, column=0, sticky=tk.W, pady=5)
        self.date_widget = DateInputWidget(frame)
        self.date_widget.grid(row=1, column=1, pady=5, sticky=tk.W)

        ttk.Label(frame, text="Футбольная команда:").grid(row=2, column=0, sticky=tk.W, pady=5)
        self.ent_team = ttk.Entry(frame, width=25)
        self.ent_team.grid(row=2, column=1, pady=5, sticky=tk.W)

        ttk.Label(frame, text="Домашний город:").grid(row=3, column=0, sticky=tk.W, pady=5)
        self.ent_city = ttk.Entry(frame, width=25)
        self.ent_city.grid(row=3, column=1, pady=5, sticky=tk.W)

        ttk.Label(frame, text="Состав:").grid(row=4, column=0, sticky=tk.W, pady=5)
        self.combo_squad = ttk.Combobox(frame, values=["Основной", "Запасной", "Резерв"], state="readonly", width=22)
        self.combo_squad.current(0)
        self.combo_squad.grid(row=4, column=1, pady=5, sticky=tk.W)

        ttk.Label(frame, text="Позиция:").grid(row=5, column=0, sticky=tk.W, pady=5)
        self.combo_pos = ttk.Combobox(frame, values=["Вратарь", "Защитник", "Полузащитник", "Нападающий"],
                                      state="readonly", width=22)
        self.combo_pos.current(0)
        self.combo_pos.grid(row=5, column=1, pady=5, sticky=tk.W)

        btn_frame = ttk.Frame(frame)
        btn_frame.grid(row=6, column=0, columnspan=2, pady=15)
        ttk.Button(btn_frame, text="Сохранить", command=self.save).pack(side=tk.LEFT, padx=5)
        ttk.Button(btn_frame, text="Отмена", command=self.destroy).pack(side=tk.LEFT, padx=5)

    def save(self) -> None:
        fio = self.ent_fio.get().strip()
        b_date = self.date_widget.get_date()
        team = self.ent_team.get().strip()
        city = self.ent_city.get().strip()
        squad = self.combo_squad.get()
        position = self.combo_pos.get()

        if not fio or not team or not city or not b_date:
            messagebox.showerror("Ошибка", "Все поля должны быть заполнены.")
            return

        self.callback(fio, b_date, team, city, squad, position)


class SearchDialog(tk.Toplevel):

    def __init__(self, parent, search_callback) -> None:
        super().__init__(parent)
        self.title("Поиск игроков")
        self.geometry("850x600")
        self.search_callback = search_callback
        self.transient(parent)
        self.grab_set()

        crit_frame = ttk.LabelFrame(self, text="Критерии поиска (отметьте флажками нужные поля)", padding=10)
        crit_frame.pack(fill=tk.X, padx=10, pady=5)


        self.strict_var = tk.BooleanVar(value=True)
        self.chk_strict = ttk.Checkbutton(crit_frame, text="Строгое соответствие (И) — совпадение всех выбранных полей",
                                          variable=self.strict_var)
        self.chk_strict.grid(row=0, column=0, columnspan=3, sticky=tk.W, pady=(0, 10))

        self.use_fio = tk.BooleanVar()
        ttk.Checkbutton(crit_frame, text="ФИО содержит:", variable=self.use_fio, command=self.toggle_fields).grid(row=1,
                                                                                                                  column=0,
                                                                                                                  sticky=tk.W)
        self.ent_fio = ttk.Entry(crit_frame, width=25)
        self.ent_fio.grid(row=1, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_date = tk.BooleanVar()
        ttk.Checkbutton(crit_frame, text="Дата рождения:", variable=self.use_date, command=self.toggle_fields).grid(
            row=2, column=0, sticky=tk.W)
        self.date_widget = DateInputWidget(crit_frame)
        self.date_widget.grid(row=2, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_team = tk.BooleanVar()
        ttk.Checkbutton(crit_frame, text="Команда содержит:", variable=self.use_team, command=self.toggle_fields).grid(
            row=3, column=0, sticky=tk.W)
        self.ent_team = ttk.Entry(crit_frame, width=25)
        self.ent_team.grid(row=3, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_city = tk.BooleanVar()
        ttk.Checkbutton(crit_frame, text="Город содержит:", variable=self.use_city, command=self.toggle_fields).grid(
            row=4, column=0, sticky=tk.W)
        self.ent_city = ttk.Entry(crit_frame, width=25)
        self.ent_city.grid(row=4, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_pos = tk.BooleanVar()
        ttk.Checkbutton(crit_frame, text="Позиция:", variable=self.use_pos, command=self.toggle_fields).grid(row=5,
                                                                                                             column=0,
                                                                                                             sticky=tk.W)
        self.combo_pos = ttk.Combobox(crit_frame, values=["Вратарь", "Защитник", "Полузащитник", "Нападающий"],
                                      state="readonly", width=22)
        self.combo_pos.current(0)
        self.combo_pos.grid(row=5, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_squad = tk.BooleanVar()
        ttk.Checkbutton(crit_frame, text="Состав:", variable=self.use_squad, command=self.toggle_fields).grid(row=6,
                                                                                                              column=0,
                                                                                                              sticky=tk.W)
        self.combo_squad = ttk.Combobox(crit_frame, values=["Основной", "Запасной", "Резерв"], state="readonly",
                                        width=22)
        self.combo_squad.current(0)
        self.combo_squad.grid(row=6, column=1, sticky=tk.W, padx=10, pady=3)

        ttk.Button(crit_frame, text="Выполнить поиск", command=self.search).grid(row=7, column=0, columnspan=2, pady=10)

        res_frame = ttk.LabelFrame(self, text="Результаты поиска", padding=5)
        res_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=5)
        self.res_table = PaginatedTableView(res_frame)
        self.res_table.pack(fill=tk.BOTH, expand=True)

        self.toggle_fields()

    def toggle_fields(self) -> None:
        self.ent_fio.config(state="normal" if self.use_fio.get() else "disabled")

        d_state = "normal" if self.use_date.get() else "disabled"
        self.date_widget.day_spin.config(state=d_state)
        self.date_widget.month_spin.config(state=d_state)
        self.date_widget.year_spin.config(state=d_state)

        self.ent_team.config(state="normal" if self.use_team.get() else "disabled")
        self.ent_city.config(state="normal" if self.use_city.get() else "disabled")
        self.combo_pos.config(state="readonly" if self.use_pos.get() else "disabled")
        self.combo_squad.config(state="readonly" if self.use_squad.get() else "disabled")

    def search(self) -> None:
        criteria: dict[str, object] = {}
        if self.use_fio.get(): criteria["fio"] = self.ent_fio.get().strip()
        if self.use_date.get(): criteria["birth_date"] = self.date_widget.get_date()
        if self.use_team.get(): criteria["team"] = self.ent_team.get().strip()
        if self.use_city.get(): criteria["city"] = self.ent_city.get().strip()
        if self.use_pos.get(): criteria["position"] = self.combo_pos.get()
        if self.use_squad.get(): criteria["squad"] = self.combo_squad.get()

        if not criteria:
            messagebox.showwarning("Предупреждение", "Выберите хотя бы один критерий для фильтрации данных!")
            return

        results = self.search_callback(criteria, self.strict_var.get())
        if results is not None:  # Если None — значит контроллер перехватил ошибку валидации
            self.res_table.set_data(results)


class DeleteDialog(tk.Toplevel):

    def __init__(self, parent, delete_callback) -> None:
        super().__init__(parent)
        self.title("Удаление игроков")
        self.geometry("500x450")
        self.delete_callback = delete_callback
        self.transient(parent)
        self.grab_set()

        frame = ttk.LabelFrame(self, text="Критерии удаления (отметьте флажками)", padding=10)
        frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        self.strict_var = tk.BooleanVar(value=True)
        self.chk_strict = ttk.Checkbutton(frame, text="Строгое соответствие (И) — удалять при совпадении всех полей",
                                          variable=self.strict_var)
        self.chk_strict.grid(row=0, column=0, columnspan=2, sticky=tk.W, pady=(0, 10))

        self.use_fio = tk.BooleanVar()
        ttk.Checkbutton(frame, text="ФИО содержит:", variable=self.use_fio, command=self.toggle_fields).grid(row=1,
                                                                                                             column=0,
                                                                                                             sticky=tk.W)
        self.ent_fio = ttk.Entry(frame, width=25)
        self.ent_fio.grid(row=1, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_date = tk.BooleanVar()
        ttk.Checkbutton(frame, text="Дата рождения:", variable=self.use_date, command=self.toggle_fields).grid(row=2,
                                                                                                               column=0,
                                                                                                               sticky=tk.W)
        self.date_widget = DateInputWidget(frame)
        self.date_widget.grid(row=2, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_team = tk.BooleanVar()
        ttk.Checkbutton(frame, text="Команда содержит:", variable=self.use_team, command=self.toggle_fields).grid(row=3,
                                                                                                                  column=0,
                                                                                                                  sticky=tk.W)
        self.ent_team = ttk.Entry(frame, width=25)
        self.ent_team.grid(row=3, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_city = tk.BooleanVar()
        ttk.Checkbutton(frame, text="Город содержит:", variable=self.use_city, command=self.toggle_fields).grid(row=4,
                                                                                                                column=0,
                                                                                                                sticky=tk.W)
        self.ent_city = ttk.Entry(frame, width=25)
        self.ent_city.grid(row=4, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_pos = tk.BooleanVar()
        ttk.Checkbutton(frame, text="Позиция:", variable=self.use_pos, command=self.toggle_fields).grid(row=5, column=0,
                                                                                                        sticky=tk.W)
        self.combo_pos = ttk.Combobox(frame, values=["Вратарь", "Защитник", "Полузащитник", "Нападающий"],
                                      state="readonly", width=22)
        self.combo_pos.current(0)
        self.combo_pos.grid(row=5, column=1, sticky=tk.W, padx=10, pady=3)

        self.use_squad = tk.BooleanVar()
        ttk.Checkbutton(frame, text="Состав:", variable=self.use_squad, command=self.toggle_fields).grid(row=6,
                                                                                                         column=0,
                                                                                                         sticky=tk.W)
        self.combo_squad = ttk.Combobox(frame, values=["Основной", "Запасной", "Резерв"], state="readonly", width=22)
        self.combo_squad.current(0)
        self.combo_squad.grid(row=6, column=1, sticky=tk.W, padx=10, pady=3)

        ttk.Button(frame, text="Удалить записи", command=self.delete_action).grid(row=7, column=0, columnspan=2,
                                                                                  pady=20)
        self.toggle_fields()

    def toggle_fields(self) -> None:
        self.ent_fio.config(state="normal" if self.use_fio.get() else "disabled")
        d_state = "normal" if self.use_date.get() else "disabled"
        self.date_widget.day_spin.config(state=d_state)
        self.date_widget.month_spin.config(state=d_state)
        self.date_widget.year_spin.config(state=d_state)

        self.ent_team.config(state="normal" if self.use_team.get() else "disabled")
        self.ent_city.config(state="normal" if self.use_city.get() else "disabled")
        self.combo_pos.config(state="readonly" if self.use_pos.get() else "disabled")
        self.combo_squad.config(state="readonly" if self.use_squad.get() else "disabled")

    def delete_action(self) -> None:
        criteria: dict[str, object] = {}
        if self.use_fio.get(): criteria["fio"] = self.ent_fio.get().strip()
        if self.use_date.get(): criteria["birth_date"] = self.date_widget.get_date()
        if self.use_team.get(): criteria["team"] = self.ent_team.get().strip()
        if self.use_city.get(): criteria["city"] = self.ent_city.get().strip()
        if self.use_pos.get(): criteria["position"] = self.combo_pos.get()
        if self.use_squad.get(): criteria["squad"] = self.combo_squad.get()

        if not criteria:
            messagebox.showwarning("Предупреждение", "Выберите хотя бы один критерий для удаления!")
            return

        count = self.delete_callback(criteria, self.strict_var.get())
        if count is not None:  # Если валидация прошла успешно
            if count > 0:
                messagebox.showinfo("Результат удаления", f"Успешно удалено записей: {count}")
                self.destroy()
            else:
                messagebox.showinfo("Результат удаления", "Записи по указанным критериям не найдены.")