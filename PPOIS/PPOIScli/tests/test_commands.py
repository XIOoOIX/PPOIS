from cli.commands import handle_command
from argparse import Namespace


def test_add_command(capsys):
    args = Namespace(command="cosmonaut", action="add", name="Ivan", age=30)

    handle_command(args)

    captured = capsys.readouterr()
    assert "Created" in captured.out


def test_list_empty(capsys):
    args = Namespace(command="cosmonaut", action="list")

    handle_command(args)

    captured = capsys.readouterr()
    assert "No cosmonauts" in captured.out or "id=" in captured.out


def test_training_command(capsys):
    # сначала добавим
    add_args = Namespace(command="cosmonaut", action="add", name="Ivan", age=30)
    handle_command(add_args)

    train_args = Namespace(command="training", action="physical", id=1)
    handle_command(train_args)

    captured = capsys.readouterr()
    assert "trained" in captured.out.lower()


def test_invalid_command(capsys):
    args = Namespace(command="unknown")

    handle_command(args)

    captured = capsys.readouterr()
    assert "Unknown command" in captured.out

def test_help_command(capsys):
    args = Namespace(command="help", topic=None)

    handle_command(args)

    captured = capsys.readouterr()
    assert "AVAILABLE COMMANDS" in captured.out


def test_help_unknown_topic(capsys):
    args = Namespace(command="help", topic="unknown")

    handle_command(args)

    captured = capsys.readouterr()
    assert "Unknown help topic" in captured.out


def test_training_invalid_id(capsys):
    args = Namespace(command="training", action="physical", id=999)

    handle_command(args)

    captured = capsys.readouterr()
    assert "Error" in captured.out


def test_mission_not_ready(capsys):
    add_args = Namespace(command="cosmonaut", action="add", name="Ivan", age=30)
    handle_command(add_args)

    mission_args = Namespace(command="mission", action="prepare", id=1)
    handle_command(mission_args)

    captured = capsys.readouterr()
    assert "NOT ready" in captured.out