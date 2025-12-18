#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

/**
 * @brief Base class for construction materials.
 */
class Material {
protected:
    std::string name;    ///< Material name.
    double weight;       ///< Weight of a single unit or batch.
    double quantity;     ///< Available quantity.
    bool damaged;        ///< Flag indicating if material is damaged.

public:
    /**
     * @brief Constructs a material with name, weight and quantity.
     * @param name Material name.
     * @param weight Weight value.
     * @param quantity Initial quantity.
     */
    Material(const std::string& name, double weight, double quantity);

    /**
     * @brief Uses a certain amount of material.
     * @param amount Amount to use.
     */
    virtual void Use(double amount);

    /**
     * @brief Checks quality and condition of the material.
     */
    virtual void CheckQuality() const;

    /**
     * @brief Prints a short description of the material.
     */
    virtual void DescribeMaterial() const;

    /**
     * @brief Gets material weight.
     * @return Weight value.
     */
    double GetWeight() const { return weight; }

    /**
        * @brief Gets material name.
        * @return Name string.
        */
    std::string GetName() const { return name; }

    /**
     * @brief Gets available quantity.
     * @return Quantity value.
     */
    double GetQuantity() const { return quantity; }

    /**
     * @brief Checks if material is damaged.
     * @return True if damaged.
     */
    bool IsDamaged() const { return damaged; }

    /**
     * @brief Virtual destructor for polymorphic use.
     */
    virtual ~Material() = default;
};

#endif // MATERIAL_H
