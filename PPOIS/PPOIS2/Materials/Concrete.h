#ifndef CONCRETE_H
#define CONCRETE_H

#include "Material.h"

/**
 * @brief Concrete mix material.
 */
class Concrete : public Material {
private:
    std::string grade;   ///< Strength grade of concrete.

public:
    /**
     * @brief Constructs a concrete material.
     * @param name Material name.
     * @param weight Weight value.
     * @param qty Quantity value.
     * @param grade Concrete grade.
     */
    Concrete(const std::string& name, double weight, double qty, const std::string& grade);

    /**
     * @brief Adds water to the concrete mix.
     * @param liters Amount of water in liters.
     */
    void AddWater(double liters);

    /**
     * @brief Mixes the concrete.
     */
    void Mix();

    /**
     * @brief Simulates concrete hardening.
     */
    void Harden();

    /**
     * @brief Describes concrete properties.
     */
    void DescribeMaterial() const override;
};

#endif // CONCRETE_H
