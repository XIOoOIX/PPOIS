#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>

class Project;
class Contract;
class Payment;

/**
 * @brief Represents a client of the construction company.
 */
class Client {
private:
    std::string name;                       ///< Client name.
    std::string contactNumber;              ///< Contact phone number.
    std::vector<Project*> projects;         ///< Client projects.
    std::vector<Contract*> contracts;       ///< Contracts with the client.
    std::vector<Payment*> payments;         ///< Client payments.
    double totalPayments;                   ///< Total amount of payments.

public:
    /**
     * @brief Constructs a client with name and contact.
     * @param name Client name.
     * @param contact Contact phone.
     */
    Client(const std::string& name, const std::string& contact);

    /**
     * @brief Adds a project to the client.
     * @param project Pointer to project.
     */
    void AddProject(Project* project);

    /**
     * @brief Registers a contract for the client.
     * @param contract Pointer to contract.
     */
    void AddContract(Contract* contract);

    /**
     * @brief Registers a payment made by the client.
     */
    Payment* MakePayment(double amount, const std::string& date, Contract* contract);
    /**
    * @brief Updates total payments.
    */
    void RegisterConfirmedPayment(double amount);
    /**
     * @brief Initiates contact from client to company.
     */
    void ContactCompany() const;

    /**
     * @brief Prints basic information about the client.
     */
    void PrintClientInfo() const;

    /**
     * @brief Gets client name.
     * @return Client name.
     */
    std::string GetName() const { return name; }

    /**
     * @brief Gets total amount of payments.
     * @return Sum of all payments.
     */
    double GetTotalPayments() const { return totalPayments; }
};

#endif // CLIENT_H
