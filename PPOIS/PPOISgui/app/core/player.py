import datetime

class Player:
    def __init__(
        self,
        fio: str,
        birth_date: datetime.date,
        team: str,
        city: str,
        squad: str,
        position: str
    ) -> None:
        self.fio: str = fio
        self.birth_date: datetime.date = birth_date
        self.team: str = team
        self.city: str = city
        self.squad: str = squad
        self.position: str = position