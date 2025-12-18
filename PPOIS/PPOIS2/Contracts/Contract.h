#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <vector>

class Client;
class Project;

/**
 * @brief Contract linking a client and a project.
 */
class Contract {
private:
    std::string contractNumber;   ///< Unique contract identifier.
    Client* client;               ///< Pointer to the client.
    Project* project;             ///< Pointer to the project.
    bool signedStatus;            ///< Flag indicating if contract is signed.
    bool completed;               ///< Flag indicating if contract is completed.

public:
    /**
     * @brief Constructs a contract for a client and project.
     * @param number Contract number.
     * @param client Pointer to client.
     * @param project Pointer to project.
     * @param amount Contract amount.
     */
    Contract(const std::string& number, Client* client, Project* project);

    /**
     * @brief Marks the contract as signed.
     */
    void Sign();

    /**
     * @brief Cancels the contract.
     */
    void Cancel();

    /**
     * @brief Marks the contract as completed.
     */
    void MarkCompleted();

    /**
     * @brief Prints basic information about the contract.
     */
    void PrintContract() const;

    /**
     * @brief Checks if contract is signed.
     * @return True if signed.
     */
    bool IsSigned() const { return signedStatus; }

    /**
     * @brief Checks if contract is completed.
     * @return True if completed.
     */
    bool IsCompleted() const { return completed; }

    /**
     * @brief Gets contract amount.
     * @return Amount value.
     */
    std::string GetContractNumber() const { return contractNumber; }
};

#endif // CONTRACT_H
