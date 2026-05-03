from models.cosmonaut import Cosmonaut


def test_cosmonaut_creation():
    c = Cosmonaut(1, "Ivan", 30)
    assert c.name == "Ivan"
    assert c.training_hours == 0


def test_training_changes_stats():
    c = Cosmonaut(1, "Ivan", 30)
    c.training_hours = 20
    c.equipment_skill = 2
    c.zero_gravity_skill = 2
    c.simulator_skill = 2

    assert c.ready_for_mission() is True


def test_not_ready_for_mission():
    c = Cosmonaut(1, "Ivan", 30)
    assert c.ready_for_mission() is False


def test_partial_training_not_ready():
    c = Cosmonaut(1, "Ivan", 30)
    c.training_hours = 20
    assert c.ready_for_mission() is False