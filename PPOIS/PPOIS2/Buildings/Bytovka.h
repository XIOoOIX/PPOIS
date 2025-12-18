#ifndef BYTOVKA_H
#define BYTOVKA_H

#include "Building.h"

/**
 * @brief Temporary building such as a site cabin or container.
 */
class Bytovka : public Building {
private:
    bool hasElectricity;    ///< Electricity connection flag.
    bool hasHeating;        ///< Heating availability flag.

public:
    /**
     * @brief Constructs a temporary building.
     * @param addr Address of the unit.
     * @param area Floor area.
     */
    Bytovka(const std::string& addr, double area);

    /**
     * @brief Connects electricity to the unit.
     */
    void ConnectElectricity();

    /**
     * @brief Turns heating on.
     */
    void TurnOnHeating();

    /**
     * @brief Turns heating off.
     */
    void TurnOffHeating();

    /**
     * @brief Prints information about the temporary building.
     */
    void PrintBuildingInfo() const override;
};

#endif // BYTOVKA_H
