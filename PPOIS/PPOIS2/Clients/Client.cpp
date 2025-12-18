#include "Client.h"
#include "../Exceptions/Exceptions.h"
#include "../Projects/Project.h"
#include "../Contracts/Contract.h"
#include "../Payment/Payment.h"
#include <iostream>

Client::Client(const std::string& clientName, const std::string& contact)
    : name(clientName),
      contactNumber(contact),
      totalPayments(0.0) {}

void Client::AddProject(Project* project) {
    if (!project) {
        throw ProjectNotFoundException("Невозможно добавить пустой проект клиенту.");
    }
    projects.push_back(project);
    std::cout << "Клиенту " << name << " добавлен новый проект.\n";
}

void Client::AddContract(Contract* contract) {
    if (!contract) {
        throw InvalidContractException("Пустой контракт.");
    }
    contracts.push_back(contract);
    std::cout << "Клиент " << name << " подписал контракт.\n";
}


Payment* Client::MakePayment(double amount, const std::string& date, Contract* contract) {
    if (amount <= 0.0) {
        throw InvalidPaymentException("Некорректная сумма оплаты.");
    }
    if (!contract) {
        throw InvalidContractException("Нельзя оплатить без контракта.");
    }

    Payment* payment = new Payment(amount, date, this, contract);
    payments.push_back(payment);
    this->RegisterConfirmedPayment(amount);
    std::cout << "Клиент " << name << " создал оплату на "
              << amount << " бел.р. за контракт.\n";
    return payment;
}


void Client::RegisterConfirmedPayment(double amount) {
    totalPayments += amount;
}

void Client::ContactCompany() const {
    std::cout << "Клиент " << name << " связывается с компанией по телефону "
              << contactNumber << ".\n";
}

void Client::PrintClientInfo() const {
    std::cout << "Имя клиента: " << name
              << "\nКонтакт: " << contactNumber
              << "\nВсего проектов: " << projects.size()
              << "\nВсего оплат: " << payments.size()
              << "\nОплачено: " << totalPayments << " бел.р.\n";
}
