#include "Project.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Project::Project(const std::string& name, double projectBudget, Client* projectClient)
    : projectName(name), budget(projectBudget), actualCost(0.0),
      startDate("не установлена"), endDate("не установлена"),
      completed(false), client(projectClient), location(nullptr) {}

void Project::StartProject() {
    if (completed) throw InvalidContractException("Проект уже завершён.");
    std::cout << "Проект " << projectName << " начат." << std::endl;
}

void Project::CompleteProject() {
    if (completed) throw InvalidContractException("Проект уже завершён.");
    completed = true;
    std::cout << "Проект " << projectName << " успешно завершён!" << std::endl;
}

void Project::AddMaterial(Material* material) {
    if (!material) throw MaterialNotFoundException("Пустой материал.");
    materialsUsed.push_back(material);
}

void Project::AddEmployee(Employee* employee) {
    if (!employee) throw EmployeeNotFoundException("Пустой сотрудник.");
    team.push_back(employee);
}

void Project::AddEquipment(Equipment* equipment) {
    if (!equipment) throw EquipmentOverloadException("Пустое оборудование.");
    equipmentUsed.push_back(equipment);
}

void Project::CalculateCost() {
    if (budget <= 0) throw InvalidContractException("Бюджет проекта некорректен.");
    actualCost = budget * 0.8;
}

void Project::ApproveBlueprint() {
    std::cout << "Чертеж проекта утверждён.\n";
}


