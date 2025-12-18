#include <gtest/gtest.h>
#include "../Clients/Client.h"
#include "../Projects/Project.h"
#include "../Payment/Payment.h"
#include "../Contracts/Contract.h"
#include "../Exceptions/exceptions.h"

TEST(ClientTest, ConstructorSetsCorrectValues) {
    Client client("ООО Ромашка", "+375291112233");
    EXPECT_EQ(client.GetName(), "ООО Ромашка");
    EXPECT_EQ(client.GetTotalPayments(), 0.0);
}

TEST(ClientTest, AddProjectNullThrows) {
    Client client("ООО Ромашка", "+375291112233");
    EXPECT_THROW(client.AddProject(nullptr), ProjectNotFoundException);
}

TEST(ClientTest, AddProjectValidNoThrow) {
    Client client("ООО Ромашка", "+375291112233");
    Project* project = new Project("Тестовый проект",1,nullptr);
    EXPECT_NO_THROW(client.AddProject(project));
    delete project;
}



TEST(ClientTest, addContractNullThrows) {
    Client client("ООО Ромашка", "+375291112233");
    EXPECT_THROW(client.AddContract(nullptr), InvalidContractException);
}

TEST(ClientTest, addContractValidNoThrow) {
    Client client("ООО Ромашка", "+375291112233");
    Contract* contract = new Contract("1", nullptr,nullptr);
    EXPECT_NO_THROW(client.AddContract(contract));
    delete contract;
}



TEST(ClientTest, MakePaymentNegativeAmountThrows) {
    Client client("ООО Ромашка", "+375291112233");
    Contract contract("1", nullptr,nullptr);
    
    EXPECT_THROW(
        client.MakePayment(-100.0, "2025-01-01", &contract),
        InvalidPaymentException
    );
}

TEST(ClientTest, MakePaymentZeroAmountThrows) {
    Client client("ООО Ромашка", "+375291112233");
    Contract contract("1", nullptr,nullptr);
    
    EXPECT_THROW(
        client.MakePayment(0.0, "2025-01-01", &contract),
        InvalidPaymentException
    );
}

TEST(ClientTest, MakePaymentNullContractThrows) {
    Client client("ООО Ромашка", "+375291112233");
    EXPECT_THROW(
        client.MakePayment(500.0, "2025-01-01", nullptr),
        InvalidContractException
    );
}

TEST(ClientTest, MakePaymentCreatesPaymentObject) {
    Client client("ООО Ромашка", "+375291112233");
    Contract contract("1", nullptr,nullptr);
    
    Payment* payment = client.MakePayment(1000.0, "2025-01-01", &contract);
    ASSERT_NE(payment, nullptr);
    EXPECT_DOUBLE_EQ(payment->GetAmount(), 1000.0);
    EXPECT_FALSE(payment->IsConfirmed());
    delete payment;
}



TEST(ClientTest, RegisterConfirmedPaymentIncreasesTotal) {
    Client client("ООО Ромашка", "+375291112233");
    double initial = client.GetTotalPayments();
    
    client.RegisterConfirmedPayment(1500.0);
    EXPECT_DOUBLE_EQ(client.GetTotalPayments(), initial + 1500.0);
    
    client.RegisterConfirmedPayment(2500.0);
    EXPECT_DOUBLE_EQ(client.GetTotalPayments(), initial + 1500.0 + 2500.0);
}

TEST(ClientTest, RegisterConfirmedPaymentZeroAmountWorks) {
    Client client("ООО Ромашка", "+375291112233");
    double initial = client.GetTotalPayments();
    
    client.RegisterConfirmedPayment(0.0);
    EXPECT_DOUBLE_EQ(client.GetTotalPayments(), initial);
}

TEST(ClientTest, RegisterConfirmedPaymentNegativeAmountWorks) {
    Client client("ООО Ромашка", "+375291112233");
    double initial = client.GetTotalPayments();
    

    client.RegisterConfirmedPayment(-100.0);
    EXPECT_DOUBLE_EQ(client.GetTotalPayments(), initial - 100.0);
}



TEST(ClientTest, FullPaymentWorkflow) {
    Client client("ООО Ромашка", "+375291112233");
    Contract contract("1", nullptr,nullptr);
    

    Payment* payment1 = client.MakePayment(10000.0, "2025-01-15", &contract);
    Payment* payment2 = client.MakePayment(15000.0, "2025-01-20", &contract);

    
    EXPECT_EQ(client.GetTotalPayments(), 25000.0);
    
    delete payment1;
    delete payment2;
}


