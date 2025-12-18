#ifndef WORKWEAR_H
#define WORKWEAR_H

#include "Equipment.h"

/**
 * @brief Personal protective clothing (PPE).
 */
class Workwear : public Equipment {
protected:
    std::string size;   ///< Clothing size.
    std::string color;  ///< Clothing color.
    bool clean;         ///< Cleanliness flag.

public:
    /**
     * @brief Constructs a workwear item.
     * @param name Item name.
     * @param cost Item cost.
     * @param size Clothing size.
     * @param color Clothing color.
     */
    Workwear(const std::string& name, double cost, const std::string& size, const std::string& color);

    /**
     * @brief Washes the workwear and marks it as clean.
     */
    void Wash();

    /**
     * @brief Checks whether the workwear is clean.
     */
    void CheckClean();

    /**
     * @brief Prints detailed information about the workwear.
     */
    void PrintInfo() const override;
};

#endif // WORKWEAR_H
