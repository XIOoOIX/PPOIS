#ifndef WOOD_H
#define WOOD_H

#include "Material.h"

/**
 * @brief Wood material used for structures or finish.
 */
class Wood : public Material {
private:
    std::string type;   ///< Wood type (e.g. pine, oak).

public:
    /**
     * @brief Constructs a wood material.
     * @param name Material name.
     * @param weight Weight value.
     * @param qty Quantity value.
     * @param type Wood type.
     */
    Wood(const std::string& name, double weight, double qty, const std::string& type);

    /**
     * @brief Dries the wood to reduce moisture.
     */
    void Dry();

    /**
     * @brief Checks quality based on type and treatment.
     */
    void CheckQuality() const override;

    /**
     * @brief Describes wood properties.
     */
    void DescribeMaterial() const override;
};

#endif // WOOD_H
