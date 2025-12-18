#include "Drill.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Drill::Drill(const std::string& name, double cost, double weight, int pow)
    : Tool(name, cost, weight, true), power(pow), safetyLock(true) {}

void Drill::StartDrilling() {
    if (!safetyLock) throw UnsafeWorkConditionException("Блокировка безопасности отключена!");
    isDrilling = true;
    std::cout << name << " начал сверлить на мощности " << power << "Вт.\n";
}

void Drill::StopDrilling() {
    isDrilling = false;
    std::cout << name << " прекратил сверление.\n";
}

void Drill::PrintInfo() const {
    std::cout << "Дрель: " << name << ", мощность " << power << " Вт.\n";
}
