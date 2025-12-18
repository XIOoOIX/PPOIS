#include "Material.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Material::Material(const std::string& matName, double matWeight, double qty)
    : name(matName), weight(matWeight), quantity(qty), damaged(false) {}

void Material::Use(double amount) {
    if (amount > quantity) throw OutOfStockException("Недостаточно материала на складе.");
    quantity -= amount;
    std::cout << name << " использован (осталось " << quantity << " ед.).\n";
}

void Material::CheckQuality() const {
    if (damaged)
        std::cout << name << " повреждён и не годится для использования.\n";
    else
        std::cout << name << " проверен, качество отличное.\n";
}

void Material::DescribeMaterial() const {
    std::cout << "Материал: " << name << ", количество: " << quantity << ", вес: " << weight << " кг.\n";
}
