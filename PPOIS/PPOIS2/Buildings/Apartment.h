#ifndef APARTMENT_H
#define APARTMENT_H

#include "Building.h"

/**
 * @brief Multi‑apartment residential building.
 */
class Apartment : public Building {
private:
    int apartmentsCount;    ///< Number of apartments.
    bool hasElevator;       ///< Elevator availability flag.

public:
    /**
     * @brief Constructs an apartment building.
     * @param addr Address of the building.
     * @param area Total area.
     * @param floors Number of floors.
     * @param count Initial number of apartments.
     */
    Apartment(const std::string& addr, double area, int floors, int count);

    /**
     * @brief Adds one apartment to the building.
     */
    void AddApartment();

    /**
     * @brief Installs an elevator in the building.
     */
    void InstallElevator();

    /**
     * @brief Prints information specific to the apartment building.
     */
    void PrintBuildingInfo() const override;
};

#endif // APARTMENT_H
