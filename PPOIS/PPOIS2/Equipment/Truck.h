#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

/**
 * @brief Cargo truck used for material transportation.
 */
class Truck : public Vehicle {
private:
    double cargoLoad;   ///< Current cargo load.
    bool loaded;        ///< Flag indicating if truck is loaded.

public:
    /**
     * @brief Constructs a truck with maximum load capacity.
     * @param name Truck name.
     * @param cost Truck cost.
     * @param maxLoad Maximum load capacity.
     */
    Truck(const std::string& name, double cost, double maxLoad);

    /**
     * @brief Loads cargo into the truck.
     * @param weight Cargo weight.
     */
    void LoadCargo(double weight);

    /**
     * @brief Unloads all cargo from the truck.
     */
    void UnloadCargo();

    /**
     * @brief Drives the truck for a given distance.
     * @param distance Distance in kilometers.
     */
    void Drive(double distance);

    /**
     * @brief Prints detailed information about the truck.
     */
    void PrintInfo() const override;
};

#endif // TRUCK_H
