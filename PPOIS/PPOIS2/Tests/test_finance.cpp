#include <gtest/gtest.h>
#include "../Contracts/Contract.h"
#include "../Payment/Payment.h"
#include "../Clients/Client.h"
#include "../Exceptions/Exceptions.h"

TEST(ContractTest, SignAndComplete) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    contract.Sign();
    EXPECT_TRUE(contract.IsSigned());
    contract.MarkCompleted();
    EXPECT_TRUE(contract.IsCompleted());
}

TEST(ContractTest, DoubleSignThrows) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    contract.Sign();
    EXPECT_THROW(contract.Sign(), InvalidContractException);
}

TEST(ContractTest, CancelCompletedThrows) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    contract.Sign();
    contract.MarkCompleted();
    EXPECT_THROW(contract.Cancel(), InvalidContractException);
}

TEST(ContractTest, CancelUnsignedContractIsAllowed) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    EXPECT_NO_THROW(contract.Cancel());
    EXPECT_FALSE(contract.IsSigned());
}

TEST(PaymentTest, ConfirmValidPayment) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    Payment payment(500.0, "01.01.2025", &client, &contract);
    EXPECT_NO_THROW(payment.ConfirmPayment());
    EXPECT_TRUE(payment.IsConfirmed());
}

TEST(PaymentTest, ConfirmZeroThrows) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    Payment payment(0.0, "01.01.2025", &client, &contract);
    EXPECT_THROW(payment.ConfirmPayment(), InvalidPaymentException);
}

TEST(PaymentTest, RejectAfterConfirmThrows) {
    Client client("Client", "123");
    Contract contract("C1", &client, nullptr);
    Payment payment(100.0, "01.01.2025", &client, &contract);
    payment.ConfirmPayment();
    EXPECT_THROW(payment.RejectPayment(), InvalidPaymentException);
}

TEST(PaymentTest, NegativeAmountInConstructorStillCheckedOnConfirm) {
    Client c("Client", "123");
    Contract ct("C1", &c, nullptr);
    Payment p(-50.0, "01.01.2025", &c, &ct);
    EXPECT_THROW(p.ConfirmPayment(), InvalidPaymentException);
}

TEST(PaymentTest, RejectUnconfirmedPaymentDoesNotThrow) {
    Client c("Client", "123");
    Contract ct("C1", &c, nullptr);
    Payment p(100.0, "01.01.2025", &c, &ct);
    EXPECT_NO_THROW(p.RejectPayment());
}
