from dataclasses import dataclass


@dataclass
class Cosmonaut:
    id: int
    name: str
    age: int

    training_hours: int = 0
    equipment_skill: int = 0
    zero_gravity_skill: int = 0
    simulator_skill: int = 0

    def ready_for_mission(self) -> bool:
        return (
            self.training_hours >= 20
            and self.equipment_skill >= 2
            and self.zero_gravity_skill >= 2
            and self.simulator_skill >= 2
        )