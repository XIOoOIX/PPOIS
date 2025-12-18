#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Employee.h"
#include <vector>

class Material;
class Project;
class Warehouse;

/**
 * @brief Supplier responsible for delivering materials.
 */
class Supplier : public Employee {
private:
    int deliveredMaterials;                    ///< Number of delivered material batches.
    std::vector<Material*> recentDeliveries;   ///< Recently delivered materials.
    double deliveryCapacity;                   ///< Maximum delivery weight per batch.

public:
    /**
     * @brief Constructs a supplier with name, salary and delivery capacity.
     * @param name Employee name.
     * @param sal Salary value.
     * @param capacity Maximum delivery weight in tons.
     */
    Supplier(const std::string& name, double sal, double capacity = 10.0);

    /**
     * @brief Delivers a material to warehouse or site.
     * @param material Pointer to material.
     * @param warehouse Target warehouse (optional).
     */
    void DeliverMaterial(Material* material, Warehouse* warehouse = nullptr);

    /**
     * @brief Checks stock or deliveries.
     * @return True if stock is sufficient.
     */
    bool CheckStock() const;

    /**
     * @brief Supplier-specific work on a project.
     * @param project Pointer to project.
     */
    void WorkOnProject(Project* project) override;

    /**
     * @brief Gets total delivered materials count.
     * @return Delivery counter.
     */
    int GetDeliveredMaterials() const { return deliveredMaterials; }

    /**
     * @brief Gets recent deliveries list.
     * @return Vector of recent materials.
     */
    const std::vector<Material*>& GetRecentDeliveries() const { return recentDeliveries; }
};

#endif // SUPPLIER_H
