import datetime
import xml.sax
import xml.dom.minidom as minidom
from app.core.player import Player


class PlayerSAXHandler(xml.sax.ContentHandler):

    def __init__(self) -> None:
        super().__init__()
        self.players: list[Player] = []
        self.current_element: str = ""
        self.fio: str = ""
        self.birth_date_str: str = ""
        self.team: str = ""
        self.city: str = ""
        self.squad: str = ""
        self.position: str = ""

    def startElement(self, name: str, attrs) -> None:
        self.current_element = name

    def characters(self, content: str) -> None:
        if self.current_element == "fio":
            self.fio += content
        elif self.current_element == "birth_date":
            self.birth_date_str += content
        elif self.current_element == "team":
            self.team += content
        elif self.current_element == "city":
            self.city += content
        elif self.current_element == "squad":
            self.squad += content
        elif self.current_element == "position":
            self.position += content

    def endElement(self, name: str) -> None:
        if name == "player":
            try:
                b_date = datetime.datetime.strptime(self.birth_date_str.strip(), "%Y-%m-%d").date()
            except ValueError:
                b_date = datetime.date(2000, 1, 1)

            player = Player(
                fio=self.fio.strip(),
                birth_date=b_date,
                team=self.team.strip(),
                city=self.city.strip(),
                squad=self.squad.strip(),
                position=self.position.strip()
            )
            self.players.append(player)

            self.fio = ""
            self.birth_date_str = ""
            self.team = ""
            self.city = ""
            self.squad = ""
            self.position = ""
        self.current_element = ""


class XMLSerializer:

    @staticmethod
    def read_players(filepath: str) -> list[Player]:
        handler = PlayerSAXHandler()
        parser = xml.sax.make_parser()
        parser.setContentHandler(handler)
        parser.parse(filepath)
        return handler.players

    @staticmethod
    def write_players(filepath: str, players: list[Player]) -> None:
        doc = minidom.Document()
        root = doc.createElement("players")
        doc.appendChild(root)

        for p in players:
            player_node = doc.createElement("player")
            mapping = [
                ("fio", p.fio),
                ("birth_date", p.birth_date.strftime("%Y-%m-%d")),
                ("team", p.team),
                ("city", p.city),
                ("squad", p.squad),
                ("position", p.position)
            ]
            for field_name, value in mapping:
                node = doc.createElement(field_name)
                text = doc.createTextNode(str(value))
                node.appendChild(text)
                player_node.appendChild(node)
            root.appendChild(player_node)

        with open(filepath, "w", encoding="utf-8") as f:
            f.write(doc.toprettyxml(indent="  ", encoding="utf-8").decode("utf-8"))