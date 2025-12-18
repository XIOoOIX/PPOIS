#include <gtest/gtest.h>
#include "../Places/Warehouse.h"
#include "../Places/Site.h"
#include "../Materials/Material.h"
#include "../Projects/Project.h"
#include "../Exceptions/Exceptions.h"

TEST(PlaceTest, ReserveAndFreePlace) {
    Place place("Address", "City", 100.0);
    EXPECT_FALSE(place.IsOccupied());
    place.ReservePlace();
    EXPECT_TRUE(place.IsOccupied());
    place.FreePlace();
    EXPECT_FALSE(place.IsOccupied());
}

TEST(PlaceTest, GetAddressReturnsCorrect) {
    Place place("Address", "City", 100.0);
    EXPECT_EQ(place.GetAddress(), "Address");
}

TEST(WarehouseTest, StoreNullMaterialThrows) {
    Warehouse warehouse("Addr", "City", 100.0, 1);
    EXPECT_THROW(warehouse.StoreMaterial(nullptr), MaterialNotFoundException);
}

TEST(WarehouseTest, OverCapacityThrows) {
    Warehouse warehouse("Addr", "City", 100.0, 1);
    Material mat("Mat", 10.0, 1.0);
    warehouse.StoreMaterial(&mat);
    EXPECT_THROW(warehouse.StoreMaterial(&mat), WarehouseCapacityException);
}

TEST(WarehouseTest, RemoveMaterialFromEmptyThrows) {
    Warehouse w("Addr", "City", 100.0, 1);
    Material mat("Mat", 10.0, 1.0);
    EXPECT_THROW(w.RemoveMaterial(&mat), OutOfStockException);
}

TEST(WarehouseTest, StoreAndRemoveMaterialOk) {
    Warehouse w("Addr", "City", 100.0, 2);
    Material m("Mat", 10.0, 1.0);
    w.StoreMaterial(&m);
    EXPECT_NO_THROW(w.RemoveMaterial(&m));
}

TEST(SiteTest, AssignProjectOnceOk) {
    Site site("Addr", "City", 200.0);
    Project project("Bridge", 1000.0, nullptr);
    EXPECT_NO_THROW(site.AssignProject(&project));
}

TEST(SiteTest, AssignProjectTwiceThrows) {
    Site site("Addr", "City", 200.0);
    Project project("Bridge", 1000.0, nullptr);
    site.AssignProject(&project);
    EXPECT_THROW(site.AssignProject(&project), InvalidContractException);
}

TEST(SiteTest, AddEquipmentNullThrows) {
    Site site("Addr", "City", 200.0);
    EXPECT_THROW(site.AddEquipment(nullptr), EquipmentOverloadException);
}

TEST(SiteTest, RemoveEquipmentOnEmptyThrows) {
    Site s("Addr", "City", 200.0);
    EXPECT_THROW(s.RemoveEquipment(nullptr), InvalidAccessException);
}
