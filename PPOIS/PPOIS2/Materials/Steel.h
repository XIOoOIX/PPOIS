#ifndef STEEL_H
#define STEEL_H

#include "Material.h"

/**
 * @brief Steel material for reinforcement or structures.
 */
class Steel : public Material {
private:
    double strength;   ///< Strength value of the steel.
    bool rusted;       ///< Rust presence flag.

public:
    /**
     * @brief Constructs a steel material.
     * @param name Material name.
     * @param weight Weight value.
     * @param qty Quantity value.
     * @param strength Strength parameter.
     */
    Steel(const std::string& name, double weight, double qty, double strength);

    /**
     * @brief Simulates welding steel elements.
     */
    void Weld();

    /**
     * @brief Checks steel for rust.
     */
    void CheckRust();

    /**
     * @brief Describes steel properties.
     */
    void DescribeMaterial() const override;
};

#endif // STEEL_H
