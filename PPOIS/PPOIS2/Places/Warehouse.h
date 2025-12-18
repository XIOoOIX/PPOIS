#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Place.h"
#include <vector>

class Material;

/**
 * @brief Warehouse for material storage.
 */
class Warehouse : public Place {
private:
    std::vector<Material*> storedMaterials; ///< List of stored materials.
    unsigned int capacity;                  ///< Maximum storage capacity.

public:
    /**
     * @brief Constructs a warehouse with capacity limit.
     * @param addr Warehouse address.
     * @param cityName City name.
     * @param areaSize Warehouse area.
     * @param maxCapacity Maximum number of material types.
     */
    Warehouse(const std::string& addr, const std::string& cityName, double areaSize, unsigned int maxCapacity);

    /**
     * @brief Stores material in warehouse.
     * @param material Pointer to material.
     */
    void StoreMaterial(Material* material);

    /**
     * @brief Removes material from warehouse.
     * @param material Pointer to material.
     */
    void RemoveMaterial(Material* material);

    /**
     * @brief Lists all stored materials.
     */
    void ListMaterials() const;

    /**
     * @brief Checks current warehouse capacity.
     */
    void CheckCapacity() const;
};

#endif // WAREHOUSE_H
