from dataclasses import dataclass
from models.cosmonaut import Cosmonaut


@dataclass
class Trainer:
    id: int
    name: str
    specialization: str
    experience_years: int

    def train_physical(self, cosmonaut: Cosmonaut) -> str:
        cosmonaut.training_hours += 5
        return f"{self.name} trained {cosmonaut.name} physically"