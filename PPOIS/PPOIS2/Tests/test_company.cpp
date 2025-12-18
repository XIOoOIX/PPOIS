#include <gtest/gtest.h>
#include "../Company/Company.h"
#include "../Branch/Branch.h"
#include "../Employees/Employee.h"
#include "../Projects/Project.h"
#include "../Clients/Client.h"
#include "../Contracts/Contract.h"
#include "../Payment/Payment.h"
#include "../Places/Warehouse.h"
#include "../Exceptions/Exceptions.h"


TEST(CompanyTest, HireEmployeeNullThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.HireEmployee(nullptr), EmployeeNotFoundException);
}

TEST(CompanyTest, HireEmployeeAddsEmployeeNoThrow) {
    Company c("TestCo", "REG123");
    Employee* e = new Employee("Иван Иванов", "Инженер", 50000.0);
    EXPECT_NO_THROW(c.HireEmployee(e));

}

TEST(CompanyTest, FireEmployeeEmptyNameThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.FireEmployee(""), EmployeeNotFoundException);
}

TEST(CompanyTest, FireNonExistingEmployeeThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.FireEmployee("Неизвестный"), EmployeeNotFoundException);
}

TEST(CompanyTest, FireExistingEmployeeRemovesFromBranchesToo) {
    Company c("TestCo", "REG123");
    Branch b1("Branch1", "City1");
    Branch b2("Branch2", "City2");

    c.AddBranch(&b1);
    c.AddBranch(&b2);

    Employee* e = new Employee("Иван Иванов", "Инженер", 50000.0);
    c.HireEmployee(e);


    b1.AddEmployee(e);
    b2.AddEmployee(e);

    EXPECT_NO_THROW(c.FireEmployee("Иван Иванов"));


    EXPECT_THROW(b1.RemoveEmployee("Иван Иванов"), EmployeeNotFoundException);
    EXPECT_THROW(b2.RemoveEmployee("Иван Иванов"), EmployeeNotFoundException);
}




TEST(CompanyTest, AddNullClientThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.AddClient(nullptr), InvalidContractException);
}

TEST(CompanyTest, AddClientNoThrow) {
    Company c("TestCo", "REG123");
    Client* cl = new Client("ООО Ромашка", "1234567890");
    EXPECT_NO_THROW(c.AddClient(cl));
    delete cl;
}

TEST(CompanyTest, SignNullContractThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.SignContract(nullptr), InvalidContractException);
}

TEST(CompanyTest, SignContractNoThrow) {
    Company c("TestCo", "REG123");
    Client* cl = new Client("ООО Ромашка", "1234567890");
    Contract* ct = new Contract("11",nullptr,nullptr);
    EXPECT_NO_THROW(c.SignContract(ct));
    delete ct;
    delete cl;
}



TEST(CompanyTest, ProcessNullPaymentThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.ProcessPayment(nullptr), InvalidPaymentException);
}

TEST(CompanyTest, AllocateNullWarehouseThrows) {
    Company c("TestCo", "REG123");
    EXPECT_THROW(c.AllocateWarehouse(nullptr), WarehouseCapacityException);
}

TEST(CompanyTest, AllocateWarehouseNoThrow) {
    Company c("TestCo", "REG123");
    Warehouse* w = new Warehouse("ул. Складская, 1", "City", 500.0, 100);
    EXPECT_NO_THROW(c.AllocateWarehouse(w));
    delete w;
}

