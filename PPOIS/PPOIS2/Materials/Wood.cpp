#include "Wood.h"
#include <iostream>

Wood::Wood(const std::string& name, double weight, double qty, const std::string& tp)
    : Material(name, weight, qty), type(tp) {}

void Wood::Dry() {
    std::cout << "Древесина высушена.\n";
}

void Wood::DescribeMaterial() const {
    std::cout << "Дерево: тип " << type << ", вес " << weight << ", количество " << quantity << ".\n";
}
