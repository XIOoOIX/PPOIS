#ifndef SHOPPING_MALL_H
#define SHOPPING_MALL_H

#include "Building.h"

/**
 * @brief Shopping mall or commercial center building.
 */
class ShoppingMall : public Building {
private:
    int shopsCount;         ///< Number of shops in the mall.
    bool parking;           ///< Parking availability flag.
    bool escalatorWorking;  ///< Escalator working status.

public:
    /**
     * @brief Constructs a shopping mall.
     * @param addr Address of the mall.
     * @param area Total area.
     * @param floors Number of floors.
     */
    ShoppingMall(const std::string& addr, double area, int floors);

    /**
     * @brief Adds a new shop to the mall.
     */
    void AddShop();

    /**
     * @brief Turns mall escalators on or off.
     * @param on True to turn on, false to turn off.
     */
    void ManageEscalator(bool on);

    /**
     * @brief Prints detailed information about the shopping mall.
     */
    void PrintBuildingInfo() const override;
};

#endif // SHOPPING_MALL_H
