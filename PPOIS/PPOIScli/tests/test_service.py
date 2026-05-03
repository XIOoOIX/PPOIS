from services.training_service import TrainingService
import pytest

def test_add_cosmonaut():
    service = TrainingService()
    c = service.add_cosmonaut("Ivan", 30)

    assert c.name == "Ivan"


def test_get_cosmonaut():
    service = TrainingService()
    c = service.add_cosmonaut("Ivan", 30)

    found = service.get_cosmonaut(c.id)

    assert found.id == c.id


def test_get_cosmonaut_error():
    service = TrainingService()


    with pytest.raises(ValueError):
        service.get_cosmonaut(999)


def test_physical_training_changes_state():
    service = TrainingService()
    c = service.add_cosmonaut("Ivan", 30)

    service.physical_training(c.id)

    updated = service.get_cosmonaut(c.id)
    assert updated.training_hours > 0




def test_equipment_training_changes_state():
    service = TrainingService()
    c = service.add_cosmonaut("Ivan", 30)

    service.equipment_training(c.id)

    updated = service.get_cosmonaut(c.id)
    assert updated.equipment_skill > 0


def test_zero_gravity_training_changes_state():
    service = TrainingService()
    c = service.add_cosmonaut("Ivan", 30)

    service.zero_gravity_training(c.id)

    updated = service.get_cosmonaut(c.id)
    assert updated.zero_gravity_skill > 0


def test_simulator_training_changes_state():
    service = TrainingService()
    c = service.add_cosmonaut("Ivan", 30)

    service.simulator_training(c.id)

    updated = service.get_cosmonaut(c.id)
    assert updated.simulator_skill > 0