#ifndef REFLECTIVE_VEST_H
#define REFLECTIVE_VEST_H

#include "Workwear.h"

/**
 * @brief High‑visibility reflective safety vest.
 */
class ReflectiveVest : public Workwear {
private:
    bool reflectiveActive;   ///< Flag indicating if reflective layer is active.

public:
    /**
     * @brief Constructs a reflective vest.
     * @param name Vest name.
     * @param cost Vest cost.
     * @param size Clothing size.
     * @param color Vest color.
     */
    ReflectiveVest(const std::string& name, double cost, const std::string& size, const std::string& color);

    /**
     * @brief Activates reflective properties (e.g. puts vest on).
     */
    void ActivateReflection();

    /**
     * @brief Deactivates reflective properties.
     */
    void DeactivateReflection();

    /**
     * @brief Prints detailed information about the vest.
     */
    void PrintInfo() const override;
};

#endif // REFLECTIVE_VEST_H
