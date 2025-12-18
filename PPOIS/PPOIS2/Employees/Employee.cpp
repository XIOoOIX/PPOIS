#include "Employee.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Employee::Employee(const std::string& name, const std::string& pos, double sal)
    : fullName(name), position(pos), salary(sal), active(true) {}

void Employee::WorkOnProject(Project* project) {
    if (!project) throw ProjectNotFoundException("Проект не найден.");
    if (!active) throw InvalidAccessException("Сотрудник не активен.");
    assignedProjects.push_back(project);
    std::cout << fullName << " работает над проектом.\n";
}

void Employee::TakeBreak() {
    std::cout << fullName << " делает перерыв.\n";
}

void Employee::ReceivePayment(double amount) {
    if (amount <= 0) throw InvalidPaymentException("Сумма должна быть положительной(и большой...).");
    salary += amount;
    std::cout << fullName << " получил выплату: " << amount << "\n";
}

void Employee::ReportWork() const {
    std::cout << fullName << " сдал отчет по работе.\n";
}

void Employee::Dismiss() {
    active = false;
    std::cout << fullName << " уволен из компании.\n";
}
