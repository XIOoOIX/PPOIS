from dataclasses import dataclass
from models.cosmonaut import Cosmonaut


@dataclass
class Equipment:
    id: int
    name: str
    equipment_type: str
    status: str = "operational"

    def use(self, cosmonaut: Cosmonaut) -> str:
        if self.status != "operational":
            return f"{self.name} is broken"

        cosmonaut.equipment_skill += 1
        return f"{cosmonaut.name} trained with {self.name}"