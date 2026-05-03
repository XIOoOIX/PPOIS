from models.cosmonaut import Cosmonaut
from models.trainer import Trainer
from models.equipment import Equipment
from models.simulator import Simulator
from models.space_station import SpaceStation


def test_trainer_increases_training():
    c = Cosmonaut(1, "Ivan", 30)
    t = Trainer(1, "Trainer", "physical", 10)

    t.train_physical(c)

    assert c.training_hours == 5


def test_equipment_training():
    c = Cosmonaut(1, "Ivan", 30)
    e = Equipment(1, "Suit", "gear")

    e.use(c)

    assert c.equipment_skill == 1


def test_simulator_training():
    c = Cosmonaut(1, "Ivan", 30)
    s = Simulator(1, "Dock", "type", 2)

    s.run(c)

    assert c.simulator_skill == 2


def test_zero_gravity_training():
    c = Cosmonaut(1, "Ivan", 30)
    st = SpaceStation(1, "ISS", "LEO", 6)

    st.train_zero_gravity(c)

    assert c.zero_gravity_skill == 1