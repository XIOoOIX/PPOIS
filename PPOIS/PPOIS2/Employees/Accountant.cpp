#include "Accountant.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Accountant::Accountant(const std::string& name, double sal)
    : Employee(name, "Бухгалтер", sal), totalPayments(0.0) {}

void Accountant::CalculateSalary() {
    std::cout << fullName << " вычисляет зарплаты.\n";
}

void Accountant::PayEmployee(Employee* employee, double amount) {
    if (!employee) throw EmployeeNotFoundException("Сотрудник не найден для выплаты.");
    if (amount <= 0) throw InvalidPaymentException("Сумма выплаты должна быть положительной.");
    totalPayments += amount;
    employee->ReceivePayment(amount);
    std::cout << fullName << " выплатил " << amount << " сотруднику " << employee->GetName() << ".\n";
}

void Accountant::WorkOnProject(Project* project) {
    try {
        Employee::WorkOnProject(project);
    } catch (const std::exception& e) {
        std::cout << "Ошибка бухгалтера: " << e.what() << std::endl;
    }
}
