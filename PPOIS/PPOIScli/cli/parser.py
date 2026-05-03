import argparse
from cli.validators import valid_age, valid_name, positive_int


def create_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="astronaut-cli",
        description="Astronaut training system",
        add_help=True
    )

    subparsers = parser.add_subparsers(dest="command")

    help_parser = subparsers.add_parser("help")
    help_parser.add_argument("topic", nargs="?", default=None)

    cosmonaut_parser = subparsers.add_parser("cosmonaut")
    cos_sub = cosmonaut_parser.add_subparsers(dest="action")

    add_parser = cos_sub.add_parser("add")
    add_parser.add_argument("-n", "--name", required=True, type=valid_name)
    add_parser.add_argument("-a", "--age", required=True, type=valid_age)

    cos_sub.add_parser("list")

    training_parser = subparsers.add_parser("training")
    train_sub = training_parser.add_subparsers(dest="action")

    for action in ["physical", "equipment", "zero", "simulator"]:
        p = train_sub.add_parser(action)
        p.add_argument("--id", required=True, type=positive_int)

    mission_parser = subparsers.add_parser("mission")
    mission_sub = mission_parser.add_subparsers(dest="action")

    prepare = mission_sub.add_parser("prepare")
    prepare.add_argument("--id", required=True, type=positive_int)

    return parser