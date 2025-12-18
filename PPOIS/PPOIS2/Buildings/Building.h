#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

class Material;
class Project;

/**
 * @brief Base class for any type of building.
 */
class Building {
protected:
    std::string address;                    ///< Building address.
    double totalArea;                       ///< Total building area.
    int floors;                             ///< Number of floors.
    bool completed;                         ///< Completion status flag.
    std::vector<Material*> usedMaterials;   ///< Materials used in construction.
    Project* project;                       ///< Associated project.

public:
    /**
     * @brief Constructs a building with address, area and floor count.
     * @param addr Address of the building.
     * @param area Total area in square meters.
     * @param floors Number of floors.
     */
    Building(const std::string& addr, double area, int floors);

    /**
     * @brief Builds the foundation of the building.
     */
    virtual void BuildFoundation();

    /**
     * @brief Performs main construction work.
     */
    virtual void Construct();

    /**
     * @brief Paints the building in a given color.
     * @param color Color name.
     */
    virtual void Paint(const std::string& color);

    /**
     * @brief Prints basic information about the building.
     */
    virtual void PrintBuildingInfo() const;

    /**
     * @brief Checks if the building is completed.
     * @return True if construction is finished.
     */
    bool IsCompleted() const { return completed; }

    /**
     * @brief Gets total area of the building.
     * @return Area value.
     */
    double GetArea() const { return totalArea; }

    /**
     * @brief Virtual destructor for polymorphic deletion.
     */
    virtual ~Building() = default;
};

#endif // BUILDING_H
