#ifndef RECONSTRUCTION_PROJECT_H
#define RECONSTRUCTION_PROJECT_H

#include "Project.h"

/**
 * @brief Project for building reconstruction and major repairs.
 */
class ReconstructionProject : public Project {
private:
    std::string buildingType;        ///< Type of building being reconstructed.
    bool needsStructuralRepair;      ///< Structural repair requirement flag.
    int roomsRenovated;              ///< Number of renovated rooms.

public:
    /**
     * @brief Constructs a reconstruction project.
     * @param name Project name.
     * @param projectBudget Project budget.
     * @param client Pointer to client.
     */
    ReconstructionProject(const std::string& name, double projectBudget, Client* client);

    /**
     * @brief Replaces old and damaged materials.
     */
    void ReplaceOldMaterials();

    /**
     * @brief Restores building facade.
     */
    void RestoreFacade();


    /**
     * @brief Calculates reconstruction project costs.
     */
    void CalculateCost() override;

    /**
     * @brief Completes reconstruction project workflow.
     */
    void CompleteProject() override;
};

#endif // RECONSTRUCTION_PROJECT_H
