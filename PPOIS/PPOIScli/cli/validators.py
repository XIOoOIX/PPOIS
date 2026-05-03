import argparse


def positive_int(value: str) -> int:
    try:
        number = int(value)
    except ValueError as exc:
        raise argparse.ArgumentTypeError("Must be an integer") from exc

    if number <= 0:
        raise argparse.ArgumentTypeError("Must be positive")

    return number


def valid_age(value: str) -> int:
    age = positive_int(value)

    if age < 18 or age > 70:
        raise argparse.ArgumentTypeError("Age must be between 18 and 70")

    return age


def valid_name(value: str) -> str:
    name = value.strip()

    if len(name) < 2:
        raise argparse.ArgumentTypeError("Name too short")

    if not name.replace(" ", "").isalpha():
        raise argparse.ArgumentTypeError("Name must contain only letters")

    return name