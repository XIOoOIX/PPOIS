#include "Manager.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Manager::Manager(const std::string& name, double sal)
    : Employee(name, "Менеджер", sal), managedProjects(0) {}

void Manager::AssignTask(Employee* employee) {
    if (!employee) throw EmployeeNotFoundException("Невозможно назначить задачу несуществующему сотруднику.");
    std::cout << fullName << " назначил задачу сотруднику " << employee->GetName() << ".\n";
}

void Manager::EvaluatePerformance() {
    std::cout << fullName << " оценивает работу подчинённых на 10 баллов.\n";
}

void Manager::PlanMeeting() {
    std::cout << fullName << " планирует встречу с клиентом.\n";
}

void Manager::WorkOnProject(Project* project) {
    try {
        Employee::WorkOnProject(project);
        managedProjects++;
        std::cout << fullName << " управляет проектом №" << managedProjects << ".\n";
    } catch (const std::exception& e) {
        std::cout << "Ошибка менеджера: " << e.what() << std::endl;
    }
}
