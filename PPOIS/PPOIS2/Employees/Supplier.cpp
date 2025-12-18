#include "Supplier.h"
#include "../Exceptions/Exceptions.h"
#include "../Materials/Material.h"
#include "../Places/Warehouse.h"
#include "../Projects/Project.h"
#include <iostream>
#include <algorithm>

Supplier::Supplier(const std::string& name, double sal, double capacity)
    : Employee(name, "Поставщик", sal),
      deliveredMaterials(0),
      deliveryCapacity(capacity) {}

void Supplier::DeliverMaterial(Material* material, Warehouse* warehouse) {
    if (!material) {
        throw MaterialNotFoundException("Поставщик не может доставить пустой материал.");
    }

    double materialWeight = material->GetWeight() * material->GetQuantity();

    if (materialWeight > deliveryCapacity) {
        throw MaterialNotFoundException("Партия материала превышает грузоподъёмность поставщика ("
                                      + std::to_string(materialWeight) + "кг > "
                                      + std::to_string(deliveryCapacity) + "кг).");
    }

    deliveredMaterials++;

    recentDeliveries.push_back(material);
    if (recentDeliveries.size() > 10) {
        recentDeliveries.erase(recentDeliveries.begin());
    }

    warehouse->StoreMaterial(material);
    std::cout << fullName << " доставил " << materialWeight
    << "т материала '" << material->GetName()
    << "' на склад. Партия #" << deliveredMaterials << std::endl;
}

bool Supplier::CheckStock() const {

    bool hasStock = !recentDeliveries.empty();

    std::cout << fullName << " проверяет наличие материалов:\n";
    std::cout << "  Всего поставок: " << deliveredMaterials << std::endl;
    std::cout << "  Количество недавних поставки: " << recentDeliveries.size() << std::endl;

    if (!recentDeliveries.empty()) {
        std::cout << "  Самая последняя поставка: " << recentDeliveries.back()->GetName() << std::endl;
    }

    return hasStock;
}

void Supplier::WorkOnProject(Project* project) {
    if (!project) {
        throw ProjectNotFoundException("Поставщик не может работать без проекта.");
    }

    try {
        Employee::WorkOnProject(project);

        std::cout << fullName << " обеспечивает материалами проект '"
                  << project->GetName() << "':" << std::endl;

        CheckStock();

        if (!recentDeliveries.empty()) {
            std::cout << "  Материалы из последних поставок доступны для проекта.\n";
        } else {
            std::cout << " Требуется новая поставка материалов!\n";
        }

    } catch (const std::exception& e) {
        std::cout << " Ошибка поставщика " << fullName << ": " << e.what() << std::endl;
        throw;
    }
}
