import tkinter as tk
from tkinter import ttk
import datetime
from app.core.player import Player


class DateInputWidget(ttk.Frame):

    def __init__(self, parent) -> None:
        super().__init__(parent)
        self.day_spin = ttk.Spinbox(self, from_=1, to=31, width=3, wrap=True)
        self.month_spin = ttk.Spinbox(self, from_=1, to=12, width=3, wrap=True)
        self.year_spin = ttk.Spinbox(self, from_=1950, to=2025, width=5, wrap=True)

        self.day_spin.set(1)
        self.month_spin.set(1)
        self.year_spin.set(2000)

        self.day_spin.pack(side=tk.LEFT, padx=2)
        ttk.Label(self, text=".").pack(side=tk.LEFT)
        self.month_spin.pack(side=tk.LEFT, padx=2)
        ttk.Label(self, text=".").pack(side=tk.LEFT)
        self.year_spin.pack(side=tk.LEFT, padx=2)

    def get_date(self) -> datetime.date | None:
        try:
            return datetime.date(int(self.year_spin.get()), int(self.month_spin.get()), int(self.day_spin.get()))
        except ValueError:
            return None


class PaginatedTableView(ttk.Frame):

    def __init__(self, parent) -> None:
        super().__init__(parent)
        self.all_data: list[Player] = []
        self.current_page: int = 1
        self.page_size: int = 10

        columns = ("fio", "birth_date", "team", "city", "squad", "position")
        self.tree = ttk.Treeview(self, columns=columns, show="headings")
        self.tree.heading("fio", text="ФИО игрока")
        self.tree.heading("birth_date", text="Дата рождения")
        self.tree.heading("team", text="Команда")
        self.tree.heading("city", text="Домашний город")
        self.tree.heading("squad", text="Состав")
        self.tree.heading("position", text="Позиция")

        for col in columns:
            self.tree.column(col, width=120, anchor=tk.CENTER)

        vsb = ttk.Scrollbar(self, orient="vertical", command=self.tree.yview)
        self.tree.configure(yscrollcommand=vsb.set)
        self.tree.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
        vsb.pack(side=tk.RIGHT, fill=tk.Y, before=self.tree)

        self.controls_frame = ttk.Frame(self)
        self.controls_frame.pack(side=tk.BOTTOM, fill=tk.X, pady=5)

        self.btn_first = ttk.Button(self.controls_frame, text="<<", width=4, command=self.go_first)
        self.btn_prev = ttk.Button(self.controls_frame, text="<", width=4, command=self.go_prev)
        self.lbl_page_info = ttk.Label(self.controls_frame, text="Страница 1 из 1")
        self.btn_next = ttk.Button(self.controls_frame, text=">", width=4, command=self.go_next)
        self.btn_last = ttk.Button(self.controls_frame, text=">>", width=4, command=self.go_last)

        ttk.Label(self.controls_frame, text="Записи на стр:").pack(side=tk.LEFT, padx=(15, 2))
        self.combo_size = ttk.Combobox(self.controls_frame, values=[5, 10, 20, 50], width=4, state="readonly")
        self.combo_size.set(10)
        self.combo_size.bind("<<ComboboxSelected>>", self.on_size_change)

        self.btn_first.pack(side=tk.LEFT, padx=2)
        self.btn_prev.pack(side=tk.LEFT, padx=2)
        self.lbl_page_info.pack(side=tk.LEFT, padx=10)
        self.btn_next.pack(side=tk.LEFT, padx=2)
        self.btn_last.pack(side=tk.LEFT, padx=2)
        self.combo_size.pack(side=tk.LEFT, padx=5)

        self.lbl_total_info = ttk.Label(self.controls_frame, text="Всего: 0")
        self.lbl_total_info.pack(side=tk.RIGHT, padx=10)

    def set_data(self, data: list[Player]) -> None:
        self.all_data = data
        self.update_view()

    def update_view(self) -> None:
        for item in self.tree.get_children():
            self.tree.delete(item)

        total_records = len(self.all_data)
        total_pages = max(1, (total_records + self.page_size - 1) // self.page_size)

        if self.current_page > total_pages:
            self.current_page = total_pages

        start_idx = (self.current_page - 1) * self.page_size
        end_idx = start_idx + self.page_size
        page_data = self.all_data[start_idx:end_idx]

        for p in page_data:
            self.tree.insert("", tk.END, values=(
                p.fio, p.birth_date.strftime("%Y-%m-%d"), p.team, p.city, p.squad, p.position
            ))

        self.lbl_page_info.config(text=f"Страница {self.current_page} из {total_pages}")
        self.lbl_total_info.config(text=f"Всего записей: {total_records} (На стр: {len(page_data)})")

    def go_first(self) -> None:
        self.current_page = 1; self.update_view()

    def go_prev(self) -> None:
        if self.current_page > 1: self.current_page -= 1; self.update_view()

    def go_next(self) -> None:
        total_pages = max(1, (len(self.all_data) + self.page_size - 1) // self.page_size)
        if self.current_page < total_pages: self.current_page += 1; self.update_view()

    def go_last(self) -> None:
        self.current_page = max(1, (len(self.all_data) + self.page_size - 1) // self.page_size)
        self.update_view()

    def on_size_change(self, event) -> None:
        self.page_size = int(self.combo_size.get())
        self.current_page = 1
        self.update_view()