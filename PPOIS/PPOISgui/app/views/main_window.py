import tkinter as tk
from tkinter import ttk
from app.views.components import PaginatedTableView


class MainWindow(tk.Tk):

    def __init__(self, controller) -> None:
        super().__init__()
        self.controller = controller
        self.title("Информационная система: Футбольные команды ")
        self.geometry("950x550")

        self.create_menu()
        self.create_toolbar()

        self.table_view = PaginatedTableView(self)
        self.table_view.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

    def create_menu(self) -> None:
        menubar = tk.Menu(self)
        file_menu = tk.Menu(menubar, tearoff=0)
        file_menu.add_command(label="Открыть XML...", command=self.controller.load_file)
        file_menu.add_command(label="Сохранить как XML...", command=self.controller.save_file)
        file_menu.add_separator()
        file_menu.add_command(label="Выход", command=self.quit)
        menubar.add_cascade(label="Файл", menu=file_menu)

        action_menu = tk.Menu(menubar, tearoff=0)
        action_menu.add_command(label="Добавить игрока", command=self.controller.open_add_dialog)
        action_menu.add_command(label="Поиск игроков", command=self.controller.open_search_dialog)
        action_menu.add_command(label="Удалить игроков", command=self.controller.open_delete_dialog)
        menubar.add_cascade(label="Действия", menu=action_menu)
        self.config(menu=menubar)

    def create_toolbar(self) -> None:
        toolbar = ttk.Frame(self, relief=tk.RAISED, borderwidth=1)
        toolbar.pack(side=tk.TOP, fill=tk.X)
        ttk.Button(toolbar, text="📂 Открыть", command=self.controller.load_file).pack(side=tk.LEFT, padx=2, pady=2)
        ttk.Button(toolbar, text="💾 Сохранить", command=self.controller.save_file).pack(side=tk.LEFT, padx=2, pady=2)
        ttk.Separator(toolbar, orient=tk.VERTICAL).pack(side=tk.LEFT, fill=tk.Y, padx=5, pady=2)
        ttk.Button(toolbar, text="➕ Добавить", command=self.controller.open_add_dialog).pack(side=tk.LEFT, padx=2,
                                                                                             pady=2)
        ttk.Button(toolbar, text="🔍 Найти", command=self.controller.open_search_dialog).pack(side=tk.LEFT, padx=2,
                                                                                             pady=2)
        ttk.Button(toolbar, text="❌ Удалить", command=self.controller.open_delete_dialog).pack(side=tk.LEFT, padx=2,
                                                                                               pady=2)