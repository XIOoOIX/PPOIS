#include "Warehouse.h"

#include <algorithm>

#include "../Exceptions/Exceptions.h"
#include "../Materials/Material.h"
#include <iostream>

Warehouse::Warehouse(const std::string& addr, const std::string& cityName, double areaSize, unsigned int maxCapacity)
    : Place(addr, cityName, areaSize), capacity(maxCapacity) {}

void Warehouse::StoreMaterial(Material* material) {
    if (!material) throw MaterialNotFoundException("Пустой материал нельзя поместить на склад.");
    if (storedMaterials.size() >= capacity)
        throw WarehouseCapacityException("Склад переполнен!");
    storedMaterials.push_back(material);
    std::cout << "Материал добавлен на склад (" << storedMaterials.size() << "/" << capacity << ").\n";
}

void Warehouse::RemoveMaterial(Material* material) {
    if (!material) {
        throw MaterialNotFoundException("Материал не найден.");
    }

    if (storedMaterials.empty()) {
        throw OutOfStockException("Склад пустой!");
    }

    auto it = std::find_if(
        storedMaterials.begin(),
        storedMaterials.end(),
        [material](Material* mat) {
            return mat == material;
        }
    );

    if (it == storedMaterials.end()) {
        throw MaterialNotFoundException("Указанный материал не найден на складе.");
    }

    std::cout << "Материал '" << (*it)->GetName()
              << "' удалён со склада.\n";

    storedMaterials.erase(it);
}

void Warehouse::ListMaterials() const {
    if (storedMaterials.empty()) {
        std::cout << "Склад пуст.\n";
        return;
    }

    std::cout << "На складе " << storedMaterials.size() << " материалов:\n";
    for (const auto* material : storedMaterials) {
        std::cout << "  - " << material->GetName() << "\n";
    }
}


void Warehouse::CheckCapacity() const {
    if (storedMaterials.size() >= capacity)
        std::cout << "Склад переполнен.\n";
    else
        std::cout << "Свободных мест на складе: " << (capacity - storedMaterials.size()) << std::endl;
}
