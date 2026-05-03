from dataclasses import dataclass
from models.cosmonaut import Cosmonaut


@dataclass
class SpaceStation:
    id: int
    name: str
    orbit_type: str
    crew_capacity: int

    def train_zero_gravity(self, cosmonaut: Cosmonaut) -> str:
        cosmonaut.zero_gravity_skill += 1
        return f"{cosmonaut.name} trained in zero gravity on {self.name}"