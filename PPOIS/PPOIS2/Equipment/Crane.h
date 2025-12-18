#ifndef CRANE_H
#define CRANE_H

#include "Vehicle.h"

/**
 * @brief Lifting crane vehicle.
 */
class Crane : public Vehicle {
private:
    double maxHeight;   ///< Maximum boom height.
    bool isExtended;    ///< Flag indicating if boom is extended.

public:
    /**
     * @brief Constructs a crane with load and height limits.
     * @param name Crane name.
     * @param cost Crane cost.
     * @param load Maximum lifting load.
     * @param height Maximum boom height.
     */
    Crane(const std::string& name, double cost, double load, double height);

    /**
     * @brief Extends the crane boom.
     * @param meters Extension height in meters.
     */
    void ExtendArm(double meters);

    /**
     * @brief Lifts a load with the crane.
     * @param weight Load weight.
     */
    void LiftLoad(double weight);

    /**
     * @brief Retracts the crane boom.
     */
    void RetractArm();

    /**
     * @brief Prints detailed information about the crane.
     */
    void PrintInfo() const override;
};

#endif // CRANE_H
