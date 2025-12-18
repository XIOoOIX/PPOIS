#ifndef PLACE_H
#define PLACE_H

#include <string>

/**
 * @brief Base class for company locations, warehouses or sites.
 */
class Place {
protected:
    std::string address;     ///< Location address.
    std::string city;        ///< City name.
    double area;             ///< Available area size.
    bool isOccupied;         ///< Occupation status flag.

public:
    /**
     * @brief Constructs a place with location info.
     * @param addr Street address.
     * @param cityName City name.
     * @param areaSize Area in square meters.
     */
    Place(const std::string& addr, const std::string& cityName, double areaSize);

    /**
     * @brief Reserves the place for use.
     */
    virtual void ReservePlace();

    /**
     * @brief Frees the place from occupation.
     */
    virtual void FreePlace();

    /**
     * @brief Prints basic location information.
     */
    virtual void PrintInfo() const;

    /**
     * @brief Checks if place is occupied.
     * @return True if occupied.
     */
    bool IsOccupied() const { return isOccupied; }

    /**
     * @brief Gets place address.
     * @return Address string.
     */
    std::string GetAddress() const { return address; }

    /**
     * @brief Virtual destructor for polymorphic use.
     */
    virtual ~Place() = default;
};

#endif // PLACE_H
