#ifndef HOUSE_H
#define HOUSE_H

#include "Building.h"

/**
 * @brief Residential house building.
 */
class House : public Building {
private:
    bool hasGarden;         ///< Flag indicating if the house has a garden.
    int rooms;              ///< Number of rooms.
    std::string ownerName;  ///< Name of the house owner.

public:
    /**
     * @brief Constructs a house with owner information.
     * @param addr Address of the house.
     * @param area Total area.
     * @param floors Number of floors.
     * @param owner Owner name.
     */
    House(const std::string& addr, double area, int floors, const std::string& owner);

    /**
     * @brief Creates or arranges a garden near the house.
     */
    void BuildGarden();

    /**
     * @brief Adds one room to the house.
     */
    void AddRoom();

    /**
     * @brief Paints the house in a given color, overriding base behavior.
     * @param color Color name.
     */
    void Paint(const std::string& color) override;

    /**
     * @brief Prints detailed information about the house.
     */
    void PrintBuildingInfo() const override;
};

#endif // HOUSE_H
