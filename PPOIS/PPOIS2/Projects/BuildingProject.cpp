#include "BuildingProject.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

BuildingProject::BuildingProject(const std::string& name, double projectBudget, Client* client)
    : Project(name, projectBudget, client),
      numberOfFloors(0), totalArea(0.0), foundationReady(false) {}

void BuildingProject::BuildFoundation() {
    foundationReady = true;
    std::cout << "Фундамент готов.\n";
}

void BuildingProject::ConstructWalls() {
    if (!foundationReady) throw UnsafeWorkConditionException("Нельзя возводить стены без фундамента!");
    std::cout << "Стены возведены.\n";
}

void BuildingProject::InstallRoof() {
    std::cout << "Крыша установлена.\n";
}

void BuildingProject::ConductFinishing() {
    std::cout << "Отделочные работы выполнены.\n";
}

void BuildingProject::CalculateCost() {
    actualCost = budget * 0.9;
}

void BuildingProject::CompleteProject() {
    completed = true;
    std::cout << "Строительный проект завершён.\n";
}
