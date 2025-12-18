#include "Engineer.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Engineer::Engineer(const std::string& name, double sal)
    : Employee(name, "Инженер", sal), blueprintReady(false) {}

void Engineer::CreateBlueprint() {
    blueprintReady = true;
    std::cout << fullName << " разработал чертеж.\n";
}

void Engineer::ApproveBlueprint() {
    if (!blueprintReady)
        throw InvalidBlueprintException("Чертеж не готов, утверждение невозможно.");
    std::cout << fullName << " утвердил чертеж.\n";
}

void Engineer::WorkOnProject(Project* project) {
    try {
        Employee::WorkOnProject(project);
        std::cout << fullName << " проверяет инженерные расчёты.\n";
    } catch (const std::exception& e) {
        std::cout << "Ошибка инженера: " << e.what() << std::endl;
    }
}
