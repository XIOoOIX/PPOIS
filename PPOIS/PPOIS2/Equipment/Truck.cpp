#include "Truck.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Truck::Truck(const std::string& name, double cost, double load)
    : Vehicle(name, cost, load), cargoLoad(0), loaded(false) {}

void Truck::LoadCargo(double weight) {
    if (weight > maxLoad) throw EquipmentOverloadException("Перегруз грузовика!");
    cargoLoad = weight;
    loaded = true;
    std::cout << name << " загружен на " << weight << " кг.\n";
}

void Truck::UnloadCargo() {
    if (!loaded) throw InvalidAccessException("Нет груза для выгрузки.");
    loaded = false;
    cargoLoad = 0;
    std::cout << name << " выгружен.\n";
}

void Truck::Drive(double distance) {
    Vehicle::Drive(distance);
    std::cout << name << " доставил груз.\n";
    this->UnloadCargo();
}

void Truck::PrintInfo() const {
    std::cout << "Грузовик: " << name << ", загрузка " << (loaded ? "есть" : "нет") << ".\n";
}
