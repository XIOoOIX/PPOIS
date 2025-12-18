#ifndef STEEL_CONSTRUCTION_H
#define STEEL_CONSTRUCTION_H

#include "Building.h"

/**
 * @brief Fast‑assembled steel frame construction.
 */
class SteelConstruction : public Building {
private:
    double frameWeight;     ///< Total weight of the steel frame.
    bool assembled;         ///< Assembly status flag.

public:
    /**
     * @brief Constructs a steel frame building.
     * @param addr Address of the building.
     * @param area Total area.
     * @param floors Number of floors.
     * @param frameW Weight of the steel frame.
     */
    SteelConstruction(const std::string& addr, double area, int floors, double frameW);

    /**
     * @brief Assembles the steel frame.
     */
    void AssembleFrame();

    /**
     * @brief Dismantles the steel construction.
     */
    void Dismantle();

    /**
     * @brief Prints information about the steel construction building.
     */
    void PrintBuildingInfo() const override;
};

#endif // STEEL_CONSTRUCTION_H
