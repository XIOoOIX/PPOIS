#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>

class Branch;
class Project;
class Employee;
class Client;
class Contract;
class Payment;
class Warehouse;

/**
 * @brief Represents a construction company with branches, projects and clients.
 */
class Company {
private:
    std::string companyName;                 ///< Company name.
    std::string registrationNumber;         ///< Registration number.
    std::vector<Branch*> branches;          ///< List of branches.
    std::vector<Employee*> employees;       ///< Company employees.
    std::vector<Client*> clients;           ///< Company clients.
    std::vector<Contract*> contracts;       ///< Signed contracts.
    std::vector<Payment*> payments;         ///< Processed payments.
    std::vector<Warehouse*> warehouses;     ///< Company warehouses.
    double balance;                         ///< Current company balance.

public:
    /**
     * @brief Constructs a company with name and registration number.
     * @param name Company name.
     * @param regNum Registration number.
     */
    Company(const std::string& name, const std::string& regNum);

    /**
     * @brief Adds a branch to the company.
     * @param branch Pointer to branch.
     */
    void AddBranch(Branch* branch);

    /**
     * @brief Hires a new employee.
     * @param employee Pointer to employee.
     */
    void HireEmployee(Employee* employee);

    /**
     * @brief Fires an employee by name.
     * @param employeeName Employee name.
     */
    void FireEmployee(const std::string& employeeName);

    /**
     * @brief Adds a client to the company.
     * @param client Pointer to client.
     */
    void AddClient(Client* client);

    /**
     * @brief Registers a signed contract.
     * @param contract Pointer to contract.
     */
    void SignContract(Contract* contract);

    /**
     * @brief Processes a payment and updates balance.
     * @param payment Pointer to payment.
     */
    void ProcessPayment(Payment* payment);

    /**
     * @brief Attaches a warehouse to the company.
     * @param warehouse Pointer to warehouse.
     */
    void AllocateWarehouse(Warehouse* warehouse);

    /**
     * @brief Calculates total expenses of the company.
     * @return Total expenses.
     */
    double CalculateTotalExpenses() const;

    /**
     * @brief Calculates total income of the company.
     * @return Total income.
     */
    double CalculateTotalIncome() const;

    /**
     * @brief Calculates company profit.
     * @return Profit value.
     */
    double CalculateProfit() const;

    /**
     * @brief Prints a short summary about the company.
     */
    void PrintCompanySummary() const;

    /**
     * @brief Transfers money to the company balance.
     * @param amount Amount to transfer.
     */
    void TransferFunds(double amount);

    /**
     * @brief Gets company name.
     * @return Company name.
     */
    std::string GetName() const { return companyName; }

    /**
     * @brief Gets current balance.
     * @return Balance value.
     */
    double GetBalance() const { return balance; }
};

#endif // COMPANY_H
