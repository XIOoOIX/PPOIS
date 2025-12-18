#include "Site.h"
#include "../Exceptions/Exceptions.h"
#include "../Equipment/Equipment.h"
#include <iostream>
#include <algorithm>

Site::Site(const std::string& addr, const std::string& cityName, double areaSize)
    : Place(addr, cityName, areaSize), currentProject(nullptr), safetyChecked(false) {}

void Site::AssignProject(Project* project) {
    if (!project) throw ProjectNotFoundException("Нельзя привязать отсутствующий проект.");
    if (currentProject) throw InvalidContractException("Другой проект уже назначен на площадке.");
    currentProject = project;
    ReservePlace();
    std::cout << "Проект привязан к стройплощадке.\n";
}

void Site::AddEquipment(Equipment* equipment) {
    if (!equipment) throw EquipmentOverloadException("Ошибка: не удалось добавить оборудование (пустой объект).");
    equipmentOnSite.push_back(equipment);
    equipment->AssignToSite();
    std::cout << "Оборудование добавлено на площадку.\n";
}

void Site::RemoveEquipment(Equipment* equipment) {
    if (!equipment) {
        throw InvalidAccessException("Невозможно удалить пустое оборудование.");
    }

    if (equipmentOnSite.empty()) {
        throw InvalidAccessException("На площадке нет оборудования.");
    }

    auto it = std::find_if(
        equipmentOnSite.begin(),
        equipmentOnSite.end(),
        [equipment](Equipment* eq) {
            return eq == equipment;
        }
    );

    if (it == equipmentOnSite.end()) {
        throw InvalidAccessException("Указанное оборудование не находится на площадке.");
    }

    std::cout << "Оборудование '" << (*it)->GetName()
              << "' удалено с площадки.\n";

    equipmentOnSite.erase(it);
}


void Site::CheckSafety() {
    safetyChecked = true;
    std::cout << "Проверка техники безопасности завершена.\n";
}

void Site::PrintSiteStatus() const {
    std::cout << "Площадка: " << address
              << "\nПроект назначен: " << (currentProject ? "да" : "нет")
              << "\nКол-во техники: " << equipmentOnSite.size()
              << "\nБезопасность проверена: " << (safetyChecked ? "да" : "нет") << std::endl;
}
