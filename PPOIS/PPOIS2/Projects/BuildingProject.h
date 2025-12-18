#ifndef BUILDING_PROJECT_H
#define BUILDING_PROJECT_H

#include "Project.h"

/**
 * @brief Project for new building construction.
 */
class BuildingProject : public Project {
private:
    int numberOfFloors;     ///< Planned number of floors.
    double totalArea;       ///< Total building area.
    bool foundationReady;   ///< Foundation completion flag.

public:
    /**
     * @brief Constructs a building construction project.
     * @param name Project name.
     * @param projectBudget Project budget.
     * @param client Pointer to client.
     */
    BuildingProject(const std::string& name, double projectBudget, Client* client);

    /**
     * @brief Builds building foundation.
     */
    void BuildFoundation();

    /**
     * @brief Constructs building walls.
     */
    void ConstructWalls();

    /**
     * @brief Installs building roof.
     */
    void InstallRoof();

    /**
     * @brief Performs finishing works.
     */
    void ConductFinishing();

    /**
     * @brief Calculates costs specific to building project.
     */
    void CalculateCost() override;

    /**
     * @brief Completes building project workflow.
     */
    void CompleteProject() override;
};

#endif // BUILDING_PROJECT_H
