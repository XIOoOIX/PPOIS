import json
from typing import List

from models.cosmonaut import Cosmonaut
from models.trainer import Trainer
from models.simulator import Simulator
from models.equipment import Equipment
from models.spacecraft import Spacecraft
from models.space_station import SpaceStation


class TrainingService:

    def __init__(self) -> None:
        self._file: str = "data.json"
        self._cosmonauts: List[Cosmonaut] = []
        self._next_id: int = 1

        self._load()

    def _load(self) -> None:
        try:
            with open(self._file, "r") as f:
                data: List[dict] = json.load(f)

                for item in data:
                    c = Cosmonaut(**item)
                    self._cosmonauts.append(c)

                if self._cosmonauts:
                    self._next_id = max(c.id for c in self._cosmonauts) + 1

        except FileNotFoundError:
            pass

    def _save(self) -> None:
        with open(self._file, "w") as f:
            json.dump([c.__dict__ for c in self._cosmonauts], f, indent=4)

    def add_cosmonaut(self, name: str, age: int) -> Cosmonaut:
        c = Cosmonaut(self._next_id, name, age)
        self._cosmonauts.append(c)
        self._next_id += 1
        self._save()
        return c

    def list_cosmonauts(self) -> List[Cosmonaut]:
        return self._cosmonauts

    def get_cosmonaut(self, cosmonaut_id: int) -> Cosmonaut:
        for c in self._cosmonauts:
            if c.id == cosmonaut_id:
                return c
        raise ValueError("Cosmonaut not found")

    def physical_training(self, cosmonaut_id: int) -> str:
        c = self.get_cosmonaut(cosmonaut_id)
        trainer = Trainer(1, "Trainer", "physical", 10)

        result = trainer.train_physical(c)
        self._save()
        return result

    def equipment_training(self, cosmonaut_id: int) -> str:
        c = self.get_cosmonaut(cosmonaut_id)
        equipment = Equipment(1, "Space Suit", "suit")

        result = equipment.use(c)
        self._save()
        return result

    def zero_gravity_training(self, cosmonaut_id: int) -> str:
        c = self.get_cosmonaut(cosmonaut_id)
        station = SpaceStation(1, "ISS", "LEO", 6)

        result = station.train_zero_gravity(c)
        self._save()
        return result

    def simulator_training(self, cosmonaut_id: int) -> str:
        c = self.get_cosmonaut(cosmonaut_id)
        simulator = Simulator(1, "Docking", "docking", 1)

        result = simulator.run(c)
        self._save()
        return result

    def prepare_mission(self, cosmonaut_id: int) -> bool:
        c = self.get_cosmonaut(cosmonaut_id)
        spacecraft = Spacecraft(1, "Souz", 3, "orbital")

        spacecraft.prepare(c)
        return c.ready_for_mission()