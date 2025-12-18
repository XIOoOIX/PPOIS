#include "Bytovka.h"
#include <iostream>

Bytovka::Bytovka(const std::string& addr, double area)
    : Building(addr, area, 1), hasElectricity(false), hasHeating(false) {}

void Bytovka::ConnectElectricity() {
    hasElectricity = true;
    std::cout << "Электричество подключено.\n";
}

void Bytovka::TurnOnHeating() {
    hasHeating = true;
    std::cout << "Обогрев включен.\n";
}

void Bytovka::TurnOffHeating() {
    hasHeating = false;
    std::cout << "Обогрев выключен.\n";
}

void Bytovka::PrintBuildingInfo() const {
    std::cout << "Бытовка по адресу: " << address
              << ", эл-во: " << (hasElectricity ? "есть" : "нет")
              << ", отопление: " << (hasHeating ? "вкл" : "выкл") << ".\n";
}
