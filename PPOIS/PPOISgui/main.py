from app.models.repository import PlayerRepository
from app.controllers.player_controller import PlayerController
from app.views.main_window import MainWindow


def main() -> None:
    model = PlayerRepository()
    controller = PlayerController()
    view = MainWindow(controller)

    controller.set_model(model)
    controller.set_view(view)

    controller.sync_data_to_view()

    view.mainloop()


if __name__ == "__main__":
    main()