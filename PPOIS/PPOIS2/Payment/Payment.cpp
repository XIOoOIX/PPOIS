#include "Payment.h"
#include "../Exceptions/Exceptions.h"
#include "../Clients/Client.h"
#include "../Contracts/Contract.h"
#include <iostream>

Payment::Payment(double amt, const std::string& payDate, Client* client, Contract* contract)
    : amount(amt),
      date(payDate),
      payer(client),
      relatedContract(contract),
      confirmed(false) {}

void Payment::ConfirmPayment() {
    if (amount <= 0.0) {
        throw InvalidPaymentException("Нельзя подтвердить оплату с нулевой или отрицательной суммой.");
    }
    if (confirmed) {
        throw InvalidPaymentException("Оплата уже подтверждена.");
    }
    confirmed = true;
    std::cout << "Оплата подтверждена на сумму " << amount << " бел.р.\n";
}

void Payment::RejectPayment() {
    if (confirmed) {
        throw InvalidPaymentException("Нельзя отклонить уже подтвержденную оплату.");
    }
    std::cout << "Оплата отклонена.\n";
}

void Payment::PrintPaymentInfo() const {
    std::cout << "Дата: " << date
              << "\nСумма: " << amount
              << "\nСтатус: " << (confirmed ? "подтверждена" : "не подтверждена") << std::endl;
}
