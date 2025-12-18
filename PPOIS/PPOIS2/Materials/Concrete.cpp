#include "Concrete.h"
#include <iostream>

Concrete::Concrete(const std::string& name, double weight, double qty, const std::string& g)
    : Material(name, weight, qty), grade(g) {}

void Concrete::AddWater(double liters) {
    std::cout << "Добавлено " << liters << " л воды в бетон.\n";
}

void Concrete::Mix() {
    std::cout << "Бетон перемешан.\n";
}

void Concrete::Harden() {
    std::cout << "Бетон затвердел.\n";
}

void Concrete::DescribeMaterial() const {
    std::cout << "Бетон марки " << grade << ", масса: " << weight << " кг, количество: " << quantity << ".\n";
}
