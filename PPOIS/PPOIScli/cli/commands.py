from services.training_service import TrainingService
from argparse import Namespace

service = TrainingService()


def show_help(topic: str | None = None) -> None:

    if topic is None:
        print("""
AVAILABLE COMMANDS:

cosmonaut add -n NAME -a AGE
cosmonaut list

training physical --id ID
training equipment --id ID
training zero --id ID
training simulator --id ID

mission prepare --id ID

help [command]
""")

    elif topic == "cosmonaut":
        print("""
COSMONAUT COMMANDS:

cosmonaut add -n NAME -a AGE
    Add new cosmonaut

cosmonaut list
    Show all cosmonauts
""")

    elif topic == "training":
        print("""
TRAINING COMMANDS:

training physical --id ID
training equipment --id ID
training zero --id ID
training simulator --id ID
""")

    elif topic == "mission":
        print("""
MISSION COMMANDS:

mission prepare --id ID
""")

    else:
        print("Unknown help topic")


def handle_command(args: Namespace) -> None:

    if args.command == "help":
        show_help(getattr(args, "topic", None))
        return

    if args.command == "cosmonaut":

        if args.action == "add":
            cosmonaut = service.add_cosmonaut(args.name, args.age)

            print(
                f"Created: id={cosmonaut.id}, "
                f"name={cosmonaut.name}, age={cosmonaut.age}"
            )

        elif args.action == "list":
            cosmonauts = service.list_cosmonauts()

            if not cosmonauts:
                print("No cosmonauts found")
                return

            for c in cosmonauts:
                print(
                    f"id={c.id} | name={c.name} | age={c.age} | "
                    f"training={c.training_hours}"
                )

    elif args.command == "training":

        try:
            if args.action == "physical":
                result = service.physical_training(args.id)

            elif args.action == "equipment":
                result = service.equipment_training(args.id)

            elif args.action == "zero":
                result = service.zero_gravity_training(args.id)

            elif args.action == "simulator":
                result = service.simulator_training(args.id)

            print(result)

        except ValueError as e:
            print(f"Error: {e}")

    elif args.command == "mission":

        try:
            if args.action == "prepare":
                ready = service.prepare_mission(args.id)

                if ready:
                    print("Cosmonaut is READY for mission")
                else:
                    print("Cosmonaut is NOT ready")

        except ValueError as e:
            print(f"Error: {e}")

    else:
        print("Unknown command. Use 'help'")