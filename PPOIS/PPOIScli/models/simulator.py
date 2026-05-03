from dataclasses import dataclass
from models.cosmonaut import Cosmonaut


@dataclass
class Simulator:
    id: int
    name: str
    simulator_type: str
    difficulty_level: int

    def run(self, cosmonaut: Cosmonaut) -> str:
        cosmonaut.simulator_skill += self.difficulty_level
        return f"{cosmonaut.name} trained in simulator {self.name}"