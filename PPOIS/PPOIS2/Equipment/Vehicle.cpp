#include "Vehicle.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Vehicle::Vehicle(const std::string& name, double cost, double load)
    : Equipment(name, cost), fuelLevel(100.0), maxLoad(load) {}

void Vehicle::Refuel(double liters) {
    fuelLevel += liters;
    std::cout << name << " заправлено на " << liters << " литров.\n";
}

void Vehicle::Drive(double distance) {
    if (fuelLevel <= 0) throw InvalidPaymentException("Нет топлива — движение невозможно.");
    fuelLevel -= distance * 0.1;
    std::cout << name << " проехал " << distance << " км.\n";
}

void Vehicle::CheckFuel() const {
    std::cout << "Уровень топлива: " << fuelLevel << "%.\n";
}

void Vehicle::PrintInfo() const {
    std::cout << "Транспорт: " << name << ", нагрузка " << maxLoad
              << ", топливо " << fuelLevel << "%.\n";
}
