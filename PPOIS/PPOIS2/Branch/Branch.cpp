#include "Branch.h"
#include "../Exceptions/exceptions.h"
#include "../Employees/Employee.h"
#include "../Projects/Project.h"
#include <iostream>
#include <algorithm>

Branch::Branch(const std::string& name, const std::string& cityName)
    : branchName(name),
      city(cityName),
      localBudget(0.0),
      active(true) {}

void Branch::AddEmployee(Employee* employee) {
    if (!employee) {
        throw EmployeeNotFoundException("Пустое значение сотрудника.");
    }
    if (!active) {
        throw InvalidAccessException("Филиал закрыт.");
    }

    std::cout << "Добавлен сотрудник в филиал: " << employee->GetName() << std::endl;
    employees.push_back(employee);
}

void Branch::RemoveEmployee(const std::string& employeeName) {
    if (employeeName.empty()) {
        throw EmployeeNotFoundException("Пустое имя сотрудника.");
    }
    if (!active) {
        throw InvalidAccessException("Филиал закрыт.");
    }

    auto it = std::find_if(
        employees.begin(),
        employees.end(),
        [&employeeName](Employee* employee) {
            return employee && employeeName == employee->GetName();
        }
    );

    if (it == employees.end()) {
        throw EmployeeNotFoundException("Сотрудник не найден: " + employeeName);
    }

    std::cout << "Удалён сотрудник: " << employeeName << std::endl;
    employees.erase(it);
}

void Branch::AssignProject(Project* project) {
    if (!active) {
        throw InvalidAccessException("Филиал закрыт.");
    }
    if (!project) {
        throw ProjectNotFoundException("Проект отсутствует.");
    }

    std::cout << "Проект '" << project->GetName() << "' назначен филиалу.\n";
    localProjects.push_back(project);
}

void Branch::CompleteLocalProject(Project* project) {
    if (!project) {
        throw ProjectNotFoundException("Неверный проект.");
    }
    if (!active) {
        throw InvalidAccessException("Филиал закрыт.");
    }

    auto it = std::find_if(
        localProjects.begin(),
        localProjects.end(),
        [project](Project* p) { return p == project; }
    );

    if (it == localProjects.end()) {
        throw ProjectNotFoundException("Проект не закреплён за этим филиалом.");
    }

    project->CompleteProject();
    std::cout << "Проект '" << project->GetName() << "' завершён филиалом.\n";
    localProjects.erase(it);
}

void Branch::IncreaseBudget(double amount) {
    if (amount < 0.0) {
        throw InvalidPaymentException("Отрицательная сумма пополнения.");
    }
    localBudget += amount;
}

void Branch::DecreaseBudget(double amount) {
    if (amount < 0.0) {
        throw InvalidPaymentException("Отрицательная сумма списания.");
    }
    if (amount > localBudget) {
        throw NotEnoughFundsException("Недостаточно средств на счёте филиала.");
    }
    localBudget -= amount;
}

void Branch::TransferEmployee(Employee* employee, Branch* anotherBranch) {
    if (!employee || !anotherBranch) {
        throw EmployeeNotFoundException("Ошибка перевода сотрудника.");
    }
    if (!active) {
        throw InvalidAccessException("Филиал закрыт.");
    }
    if (!anotherBranch->IsActive()) {
        throw InvalidAccessException("Целевой филиал закрыт.");
    }

    auto it = std::find_if(
        employees.begin(),
        employees.end(),
        [employee](Employee* e) { return e == employee; }
    );

    if (it == employees.end()) {
        throw EmployeeNotFoundException("Сотрудник не найден в текущем филиале.");
    }

    std::cout << "Сотрудник " << employee->GetName()
              << " переведён в филиал города " << anotherBranch->GetCity() << ".\n";

    anotherBranch->employees.push_back(employee);
    employees.erase(it);
}

void Branch::InspectStatus() const {
    std::cout << "Филиал " << branchName
              << " в городе " << city
              << " — состояние: " << (active ? "Активен" : "Закрыт") << std::endl;
}

void Branch::CloseBranch() {
    if (!active) {
        std::cout << "Филиал уже закрыт.\n";
        return;
    }
    active = false;
    std::cout << "Филиал закрыт.\n";
}
