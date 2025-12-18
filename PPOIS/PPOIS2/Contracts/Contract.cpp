#include "Contract.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Contract::Contract(const std::string& number, Client* clientRef, Project* projectRef)
    : contractNumber(number), client(clientRef), project(projectRef),
       signedStatus(false), completed(false) {}

void Contract::Sign() {
    if (signedStatus) throw InvalidContractException("Контракт уже подписан.");
    signedStatus = true;
    std::cout << "Контракт №" << contractNumber << " подписан.\n";
}

void Contract::Cancel() {
    if (completed) throw InvalidContractException("Нельзя отменить завершённый контракт.");
    signedStatus = false;
    std::cout << "Контракт №" << contractNumber << " отменён.\n";
}

void Contract::MarkCompleted() {
    if (!signedStatus) throw InvalidContractException("Контракт не подписан, нельзя завершить.");
    completed = true;
    std::cout << "Контракт №" << contractNumber << " завершён.\n";
}

void Contract::PrintContract() const {
    std::cout << "Контракт №" << contractNumber
              << "\nПодписан: " << (signedStatus ? "да" : "нет")
              << "\nЗавершён: " << (completed ? "да" : "нет") << std::endl;
}
