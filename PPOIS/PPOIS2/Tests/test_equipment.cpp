#include <gtest/gtest.h>
#include "../Equipment/Crane.h"
#include "../Equipment/Truck.h"
#include "../Equipment/Drill.h"
#include "../Equipment/Workwear.h"
#include "../Equipment/ReflectiveVest.h"
#include "../Equipment/MeasuringTool.h"
#include "../Exceptions/Exceptions.h"


TEST(EquipmentBaseTest, StartAndStop) {
    Equipment e("Equip", 1000.0);
    e.Start();
    EXPECT_THROW(e.Start(), EquipmentOverloadException);
    e.Stop();
    EXPECT_THROW(e.Stop(), InvalidAccessException);
}

TEST(EquipmentBaseTest, AssignToSiteNoThrow) {
    Equipment e("Equip", 1000.0);
    EXPECT_NO_THROW(e.AssignToSite());
}


TEST(ToolTest, UseAndRepair) {
    Tool t("Tool", 1000.0, 2.0, true);
    EXPECT_NO_THROW(t.UseTool());
    EXPECT_NO_THROW(t.Repair());
}

TEST(ToolTest, CheckConditionNoThrow) {
    Tool t("Tool", 1000.0, 2.0, false);
    EXPECT_NO_THROW(t.CheckCondition());
}

TEST(WorkwearTest, WashAndCheckClean) {
    Workwear w("Wear", 500.0, "L", "orange");
    EXPECT_NO_THROW(w.CheckClean());
    EXPECT_NO_THROW(w.Wash());
}

TEST(WorkwearTest, MultipleWashCalls) {
    Workwear w("Wear", 500.0, "L", "orange");
    w.Wash();
    w.Wash();
    EXPECT_NO_THROW(w.CheckClean());
}

TEST(CraneTest, ExtendWithinLimitOk) {
    Crane c("Crane", 100000.0, 2000.0, 20.0);
    EXPECT_NO_THROW(c.ExtendArm(10.0));
}

TEST(CraneTest, ExtendOverLimitThrows) {
    Crane c("Crane", 100000.0, 2000.0, 20.0);
    EXPECT_THROW(c.ExtendArm(30.0), EquipmentOverloadException);
}

TEST(CraneTest, LiftOverloadThrows) {
    Crane c("Crane", 100000.0, 2000.0, 20.0);
    EXPECT_THROW(c.LiftLoad(3000.0), EquipmentOverloadException);
}

TEST(TruckTest, LoadOverMaxThrows) {
    Truck t("Truck", 50000.0, 1000.0);
    EXPECT_THROW(t.LoadCargo(1500.0), EquipmentOverloadException);
}

TEST(TruckTest, LoadAndUnloadOk) {
    Truck t("Truck", 50000.0, 1000.0);
    t.LoadCargo(500.0);
    EXPECT_NO_THROW(t.UnloadCargo());
}


TEST(DrillTest, StartAndStop) {
    Drill d("Drill", 1000.0, 2.0, 500);
    EXPECT_NO_THROW(d.StartDrilling());
    EXPECT_NO_THROW(d.StopDrilling());
}

TEST(DrillTest, MultipleStartStop) {
    Drill d("Drill", 1000.0, 2.0, 500);
    d.StartDrilling();
    d.StopDrilling();
    EXPECT_NO_THROW(d.StartDrilling());
}

TEST(MeasuringToolTest, MeasureDistanceNoThrow) {
    MeasuringTool m("Measure", 500.0, 1.0, 1.0);
    EXPECT_NO_THROW(m.MeasureDistance(10.0));
}

TEST(ReflectiveVestTest, ActivateAndDeactivate) {
    ReflectiveVest v("Vest", 200.0, "L", "green");
    v.ActivateReflection();
    v.DeactivateReflection();
    EXPECT_NO_THROW(v.PrintInfo());
}

TEST(ReflectiveVestTest, MultipleToggle) {
    ReflectiveVest v("Vest", 200.0, "L", "green");
    v.ActivateReflection();
    v.DeactivateReflection();
    v.ActivateReflection();
    EXPECT_NO_THROW(v.PrintInfo());
}