#include <gtest/gtest.h>
#include "../Branch/Branch.h"
#include "../Employees/Employee.h"
#include "../Projects/Project.h"
#include "../Exceptions/exceptions.h"

TEST(BranchTest, BranchStartsActive) {
    Branch branch("MainBranch", "City");
    EXPECT_TRUE(branch.IsActive());
}

TEST(BranchTest, CloseBranchMakesInactive) {
    Branch branch("MainBranch", "City");
    branch.CloseBranch();
    EXPECT_FALSE(branch.IsActive());
}

TEST(BranchTest, IncreaseAndDecreaseBudget) {
    Branch branch("MainBranch", "City");
    EXPECT_NO_THROW(branch.IncreaseBudget(500.0));
    EXPECT_THROW(branch.DecreaseBudget(1000.0), NotEnoughFundsException);
}

TEST(BranchTest, BudgetCannotDecreaseBelowZero) {
    Branch b("Main", "City");
    b.IncreaseBudget(1000.0);
    EXPECT_NO_THROW(b.DecreaseBudget(500.0));
}

TEST(BranchTest, AddEmployeeNullThrows) {
    Branch branch("Main", "Minsk");
    EXPECT_THROW(branch.AddEmployee(nullptr), EmployeeNotFoundException);
}

TEST(BranchTest, AddEmployeeToClosedBranchThrows) {
    Branch branch("Main", "Minsk");
    branch.CloseBranch();
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    EXPECT_THROW(branch.AddEmployee(emp), InvalidAccessException);
    delete emp;
}

TEST(BranchTest, AddEmployeeStoresEmployeeAndDoesNotThrow) {
    Branch branch("Main", "Minsk");
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    EXPECT_NO_THROW(branch.AddEmployee(emp));

}

TEST(BranchTest, RemoveEmployeeEmptyNameThrows) {
    Branch branch("Main", "Minsk");
    EXPECT_THROW(branch.RemoveEmployee(""), EmployeeNotFoundException);
}

TEST(BranchTest, RemoveEmployeeFromClosedBranchThrows) {
    Branch branch("Main", "Minsk");
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    branch.AddEmployee(emp);
    branch.CloseBranch();
    EXPECT_THROW(branch.RemoveEmployee("Иван Иванов"), InvalidAccessException);

}

TEST(BranchTest, RemoveExistingEmployeeDoesNotThrow) {
    Branch branch("Main", "Minsk");
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    branch.AddEmployee(emp);
    EXPECT_NO_THROW(branch.RemoveEmployee("Иван Иванов"));
}

TEST(BranchTest, RemoveNonExistingEmployeeThrows) {
    Branch branch("Main", "Minsk");
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    branch.AddEmployee(emp);
    EXPECT_THROW(branch.RemoveEmployee("Пётр Петров"), EmployeeNotFoundException);
}

TEST(BranchTest, AssignProjectToClosedBranchThrows) {
    Branch branch("Main", "Minsk");
    branch.CloseBranch();
    Project* pr = new Project("Проект", 1000.0, nullptr);
    EXPECT_THROW(branch.AssignProject(pr), InvalidAccessException);
    delete pr;
}

TEST(BranchTest, AssignNullProjectThrows) {
    Branch branch("Main", "Minsk");
    EXPECT_THROW(branch.AssignProject(nullptr), ProjectNotFoundException);
}

TEST(BranchTest, AssignProjectStoresProject) {
    Branch branch("Main", "Minsk");
    Project* pr = new Project("Проект", 1000.0, nullptr);
    EXPECT_NO_THROW(branch.AssignProject(pr));

}

TEST(BranchTest, CompleteLocalProjectNullThrows) {
    Branch branch("Main", "Minsk");
    EXPECT_THROW(branch.CompleteLocalProject(nullptr), ProjectNotFoundException);
}

TEST(BranchTest, CompleteLocalProjectClosedBranchThrows) {
    Branch branch("Main", "Minsk");
    Project* pr = new Project("Проект", 1000.0, nullptr);
    branch.AssignProject(pr);
    branch.CloseBranch();
    EXPECT_THROW(branch.CompleteLocalProject(pr), InvalidAccessException);
    delete pr;
}

TEST(BranchTest, CompleteAssignedProjectDoesNotThrow) {
    Branch branch("Main", "Minsk");
    Project* pr = new Project("Проект", 1000.0, nullptr);
    branch.AssignProject(pr);
    EXPECT_NO_THROW(branch.CompleteLocalProject(pr));
    delete pr;
}

TEST(BranchTest, TransferEmployeeNullThrows) {
    Branch from("From", "Minsk");
    Branch to("To", "Gomel");
    EXPECT_THROW(from.TransferEmployee(nullptr, &to), EmployeeNotFoundException);
}

TEST(BranchTest, TransferEmployeeToClosedBranchThrows) {
    Branch from("From", "Minsk");
    Branch to("To", "Gomel");
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    from.AddEmployee(emp);
    to.CloseBranch();
    EXPECT_THROW(from.TransferEmployee(emp, &to), InvalidAccessException);
    delete emp;
}

TEST(BranchTest, TransferEmployeeBetweenBranchesNoThrow) {
    Branch from("From", "Minsk");
    Branch to("To", "Gomel");
    Employee* emp = new Employee("Иван Иванов", "Инженер", 50000.0);
    from.AddEmployee(emp);
    EXPECT_NO_THROW(from.TransferEmployee(emp, &to));


}
