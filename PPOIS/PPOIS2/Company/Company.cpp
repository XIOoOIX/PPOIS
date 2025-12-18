#include "Company.h"
#include "../Exceptions/Exceptions.h"
#include "../Projects/Project.h"
#include "../Branch/Branch.h"
#include "../Employees/Employee.h"
#include "../Clients/Client.h"
#include "../Contracts/Contract.h"
#include "../Payment/Payment.h"
#include "../Places/Warehouse.h"
#include <iostream>
#include <algorithm>

Company::Company(const std::string& name, const std::string& regNum)
    : companyName(name),
      registrationNumber(regNum),
      balance(0.0){}


void Company::AddBranch(Branch* branch) {
    if (!branch) {
        throw InvalidContractException("Попытка добавить пустой филиал.");
    }
    branches.push_back(branch);
    std::cout << "Добавлен новый филиал.\n";
}


void Company::HireEmployee(Employee* employee) {
    if (!employee) {
        throw EmployeeNotFoundException("Попытка нанять несуществующего сотрудника.");
    }
    employees.push_back(employee);
    std::cout << "Нанят новый сотрудник: " << employee->GetName() << std::endl;
}

void Company::FireEmployee(const std::string& employeeName) {
    if (employeeName.empty()) {
        throw EmployeeNotFoundException("Имя сотрудника пустое.");
    }

    auto it = std::find_if(
        employees.begin(),
        employees.end(),
        [&employeeName](Employee* e) {
            return e && e->GetName() == employeeName;
        }
    );

    if (it == employees.end()) {
        throw EmployeeNotFoundException("Сотрудник не найден в компании: " + employeeName);
    }

    Employee* toFire = *it;

    for (Branch* branch : branches) {
        if (!branch) continue;
        try {
            branch->RemoveEmployee(employeeName);
        } catch (const EmployeeNotFoundException&) {
        }
    }

    toFire->Dismiss();
    std::cout << "Сотрудник уволен: " << employeeName << std::endl;

    employees.erase(it);
    delete toFire;
}

void Company::AddClient(Client* client) {
    if (!client) {
        throw InvalidContractException("Невозможно добавить пустого клиента.");
    }
    clients.push_back(client);
    std::cout << "Клиент добавлен.\n";
}

void Company::SignContract(Contract* contract) {
    if (!contract) {
        throw InvalidContractException("Контракт пустой.");
    }
    contracts.push_back(contract);
    contract->Sign();
    std::cout << "Контракт " << contract->GetContractNumber() << " подписан.\n";
}


void Company::ProcessPayment(Payment* payment) {
    if (!payment) {
        throw InvalidPaymentException("Нельзя обработать пустой платёж.");
    }
    payments.push_back(payment);

    if (!payment->IsConfirmed()) {
        payment->ConfirmPayment();
    }

    balance += payment->GetAmount();
    std::cout << "Платёж обработан. Баланс: " << balance << std::endl;
}

void Company::AllocateWarehouse(Warehouse* warehouse) {
    if (!warehouse) {
        throw WarehouseCapacityException("Пустой склад.");
    }
    warehouses.push_back(warehouse);
    std::cout << "Склад привязан к компании.\n";
}

double Company::CalculateTotalExpenses() const {
    double expenses = balance * 0.3;
    return expenses;
}

double Company::CalculateTotalIncome() const {
    double income = balance * 0.6;
    return income;
}

double Company::CalculateProfit() const {
    return CalculateTotalIncome() - CalculateTotalExpenses();
}

void Company::PrintCompanySummary() const {
    std::cout << "Компания: " << companyName << "\n"
              << "Рег. номер: " << registrationNumber << "\n"
              << "Филиалов: " << branches.size() << "\n"
              << "Сотрудников: " << employees.size() << "\n"
              << "Клиентов: " << clients.size() << "\n"
              << "Контрактов: " << contracts.size() << "\n"
              << "Баланс: " << balance << " руб.\n";
}

void Company::TransferFunds(double amount) {
    if (amount == 0.0) {
        return;
    }
    balance += amount;
    std::cout << "Переведено средств: " << amount
              << ". Новый баланс: " << balance << " руб.\n";
}
