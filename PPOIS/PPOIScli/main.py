from cli.parser import create_parser
from cli.commands import handle_command


def main() -> None:
    parser = create_parser()
    args = parser.parse_args()

    if args.command is None:
        print("Use 'help' to see available commands")
        return

    handle_command(args)


if __name__ == "__main__":
    main()