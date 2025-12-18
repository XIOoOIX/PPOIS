#include "ReconstructionProject.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

ReconstructionProject::ReconstructionProject(const std::string& name, double projectBudget, Client* client)
    : Project(name, projectBudget, client),
      buildingType("не указано"), needsStructuralRepair(true), roomsRenovated(0) {}


void ReconstructionProject::ReplaceOldMaterials() {
    std::cout << "Материалы заменены на новые.\n";
}

void ReconstructionProject::RestoreFacade() {
    std::cout << "Фасад восстановлен.\n";
}


void ReconstructionProject::CalculateCost() {
    actualCost = budget * 0.75;
}

void ReconstructionProject::CompleteProject() {
    completed = true;
    std::cout << "Проект реконструкции завершён.\n";
}
