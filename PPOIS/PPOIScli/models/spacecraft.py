from dataclasses import dataclass
from models.cosmonaut import Cosmonaut


@dataclass
class Spacecraft:
    id: int
    name: str
    capacity: int
    mission_type: str

    def prepare(self, cosmonaut: Cosmonaut) -> str:
        return f"{cosmonaut.name} assigned to spacecraft {self.name}"