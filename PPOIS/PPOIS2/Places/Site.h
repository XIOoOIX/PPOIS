#ifndef SITE_H
#define SITE_H

#include "Place.h"
#include <vector>

class Project;
class Equipment;

/**
 * @brief Construction site for building projects.
 */
class Site : public Place {
private:
    Project* currentProject;     ///< Current project on site.
    std::vector<Equipment*> equipmentOnSite; ///< Equipment assigned to site.
    bool safetyChecked;          ///< Safety inspection status.

public:
    /**
     * @brief Constructs a construction site.
     * @param addr Site address.
     * @param cityName City name.
     * @param areaSize Site area.
     */
    Site(const std::string& addr, const std::string& cityName, double areaSize);

    /**
     * @brief Assigns a project to the site.
     * @param project Pointer to project.
     */
    void AssignProject(Project* project);

    /**
     * @brief Adds equipment to the site.
     * @param equipment Pointer to equipment.
     */
    void AddEquipment(Equipment* equipment);

    /**
     * @brief Removes equipment from the site.
     * @param equipment Pointer to equipment.
     */
    void RemoveEquipment(Equipment* equipment);

    /**
     * @brief Performs safety inspection.
     */
    void CheckSafety();

    /**
     * @brief Prints current site status.
     */
    void PrintSiteStatus() const;
};

#endif // SITE_H
