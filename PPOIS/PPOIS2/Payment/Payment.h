#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

class Client;
class Contract;

/**
 * @brief Payment information for a specific contract.
 */
class Payment {
private:
    double amount;           ///< Payment amount.
    std::string date;        ///< Payment date.
    Client* payer;           ///< Pointer to paying client.
    Contract* relatedContract; ///< Associated contract.
    bool confirmed;          ///< Confirmation status flag.
    double paidAmount{0.0};  ///<How much paid.

public:
    /**
     * @brief Constructs a payment with client and contract info.
     * @param amount Payment amount.
     * @param date Payment date string.
     * @param client Pointer to client.
     * @param contract Pointer to related contract.
     */
    Payment(double amount, const std::string& date, Client* client, Contract* contract);

    /**
     * @brief Confirms the payment as processed.
     */
    void ConfirmPayment();

    /**
     * @brief Rejects the payment.
     */
    void RejectPayment();

    /**
     * @brief Prints payment details.
     */
    void PrintPaymentInfo() const;

    /**
     * @brief Gets payment amount.
     * @return Amount value.
     */
    double GetAmount() const { return amount; }

    /**
        * @brief Gets payment amount that was paid.
        * @return Paid amount value.
        */
    double GetPaidAmount() const { return paidAmount; }
    /**
     * @brief Checks if payment is confirmed.
     * @return True if confirmed.
     */
    bool IsConfirmed() const { return confirmed; }
};

#endif // PAYMENT_H
