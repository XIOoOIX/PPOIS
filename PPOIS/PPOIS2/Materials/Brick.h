#ifndef BRICK_H
#define BRICK_H

#include "Material.h"

/**
 * @brief Brick material used for masonry.
 */
class Brick : public Material {
private:
    std::string color;   ///< Brick color.
    bool isFireproof;    ///< Fire resistance flag.

public:
    /**
     * @brief Constructs a brick material.
     * @param name Material name.
     * @param weight Weight value.
     * @param qty Quantity value.
     * @param color Brick color.
     * @param fireproof True if fireproof.
     */
    Brick(const std::string& name, double weight, double qty, const std::string& color, bool fireproof);

    /**
     * @brief Checks brick durability.
     */
    void CheckDurability();

    /**
     * @brief Describes brick properties.
     */
    void DescribeMaterial() const override;
};

#endif // BRICK_H
