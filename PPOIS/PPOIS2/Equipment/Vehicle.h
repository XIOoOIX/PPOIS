#ifndef VEHICLE_H
#define VEHICLE_H

#include "Equipment.h"

/**
 * @brief Transport vehicle used on construction projects.
 */
class Vehicle : public Equipment {
protected:
    double fuelLevel;   ///< Current fuel level (percent or liters).
    double maxLoad;     ///< Maximum allowed load.

public:
    /**
     * @brief Constructs a vehicle with load capacity.
     * @param name Vehicle name.
     * @param cost Vehicle cost.
     * @param maxLoad Maximum load capacity.
     */
    Vehicle(const std::string& name, double cost, double maxLoad);

    /**
     * @brief Adds fuel to the vehicle.
     * @param liters Amount of fuel.
     */
    void Refuel(double liters);

    /**
     * @brief Drives the vehicle for a given distance.
     * @param distance Distance in kilometers.
     */
    void Drive(double distance);

    /**
     * @brief Prints current fuel level.
     */
    void CheckFuel() const;

    /**
     * @brief Prints detailed information about the vehicle.
     */
    void PrintInfo() const override;
};

#endif // VEHICLE_H
