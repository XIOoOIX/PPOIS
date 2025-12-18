#include "Steel.h"
#include <iostream>

Steel::Steel(const std::string& name, double weight, double qty, double str)
    : Material(name, weight, qty), strength(str), rusted(false) {}

void Steel::Weld() {
    std::cout << "Сварены металлические части.\n";
}

void Steel::CheckRust() {
    rusted = false;
    std::cout << "Сталь чистая, ржавчины нет.\n";
}

void Steel::DescribeMaterial() const {
    std::cout << "Сталь " << strength << " МПа, количество: " << quantity << ", вес: " << weight << ".\n";
}
