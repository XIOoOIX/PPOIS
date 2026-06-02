import re

class PlayerValidator:

    _TEXT_PATTERN: re.Pattern = re.compile(r"^[A-Za-zА-Яа-яЁё\s-]+$")

    @staticmethod
    def validate_text_field(value: str) -> bool:
        if not value or not value.strip():
            return False
        return bool(PlayerValidator._TEXT_PATTERN.match(value))

    @staticmethod
    def validate_year(date_obj) -> bool:
        if not date_obj:
            return False
        return 1950 <= date_obj.year <= 2025

    @staticmethod
    def get_validation_error(fio: str, city: str, birth_date):
        if not PlayerValidator.validate_text_field(fio):
            return "ФИО игрока заполнено некорректно! Не должно содержать цифр или спецсимволов."
        if not PlayerValidator.validate_text_field(city):
            return "Название города заполнено некорректно! Не должно содержать цифр или спецсимволов."
        if not PlayerValidator.validate_year(birth_date):
            return "Год рождения должен находиться в диапазоне от 1950 до 2025 года."
        return None

    @staticmethod
    def validate_search_criteria(criteria):
        if "fio" in criteria and not PlayerValidator.validate_text_field(criteria["fio"]):
            return "Критерий поиска 'ФИО' заполнен некорректно. Цифры и спецсимволы запрещены."
        if "city" in criteria and not PlayerValidator.validate_text_field(criteria["city"]):
            return "Критерий поиска 'Город' заполнен некорректно. Цифры и спецсимволы запрещены."
        if "birth_date" in criteria and not PlayerValidator.validate_year(criteria["birth_date"]):
            return "Выбранный в поиске год рождения выходит за границы диапазона 1950 - 2025 гг."
        return None