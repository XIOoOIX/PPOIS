#include "DemolitionProject.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

DemolitionProject::DemolitionProject(const std::string& name, double projectBudget, Client* client)
    : Project(name, projectBudget, client),
      permitApproved(false), workersInvolved(0), debrisRemoved(false) {}

void DemolitionProject::RequestPermit() {
    permitApproved = true;
    std::cout << "Разрешение на снос получено.\n";
}



void DemolitionProject::RemoveDebris() {
    debrisRemoved = true;
    std::cout << "Мусор после сноса убран.\n";
}


void DemolitionProject::CalculateCost() {
    actualCost = budget * 0.65;
}

void DemolitionProject::CompleteProject() {
    if (!permitApproved) throw InvalidAccessException("Нет разрешения на снос!");
    completed = true;
    std::cout << "Снос здания выполнен.\n";
}
