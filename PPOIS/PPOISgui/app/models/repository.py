from app.core.player import Player


class PlayerRepository:

    def __init__(self) -> None:
        self._players: list[Player] = []
        self._listeners = []

    def add_listener(self, callback) -> None:
        self._listeners.append(callback)

    def notify_listeners(self) -> None:
        for callback in self._listeners:
            callback()

    @property
    def all_players(self) -> list[Player]:
        return self._players

    @all_players.setter
    def all_players(self, players: list[Player]) -> None:
        self._players = players
        self.notify_listeners()

    def add_player(self, player: Player) -> None:
        self._players.append(player)
        self.notify_listeners()

    def filter_players(self, criteria: dict[str, object], strict: bool) -> list[Player]:
        if not criteria:
            return []

        result: list[Player] = []
        for p in self._players:
            field_matches: list[bool] = []

            if "fio" in criteria:
                field_matches.append(criteria["fio"].lower() in p.fio.lower())
            if "birth_date" in criteria:
                field_matches.append(p.birth_date == criteria["birth_date"])
            if "team" in criteria:
                field_matches.append(criteria["team"].lower() in p.team.lower())
            if "city" in criteria:
                field_matches.append(criteria["city"].lower() in p.city.lower())
            if "position" in criteria:
                field_matches.append(criteria["position"].lower() == p.position.lower())
            if "squad" in criteria:
                field_matches.append(criteria["squad"].lower() == p.squad.lower())

            if strict:
                if all(field_matches):
                    result.append(p)
            else:
                if any(field_matches):
                    result.append(p)

        return result

    def delete_players(self, criteria: dict[str, object], strict: bool) -> int:
        to_delete = self.filter_players(criteria, strict)
        count = len(to_delete)
        if count > 0:
            self._players = [p for p in self._players if p not in to_delete]#################################################################################
            self.notify_listeners()
        return count