#include <gtest/gtest.h>
#include "../Projects/BuildingProject.h"
#include "../Projects/DemolitionProject.h"
#include "../Projects/ReconstructionProject.h"
#include "../Exceptions/Exceptions.h"

TEST(ProjectTest, StartAndCompleteProject) {
    Project project("BaseProject", 1000.0, nullptr);
    EXPECT_NO_THROW(project.StartProject());
    EXPECT_NO_THROW(project.CompleteProject());
    EXPECT_TRUE(project.IsCompleted());
}

TEST(ProjectTest, DoubleCompleteThrows) {
    Project project("BaseProject", 1000.0, nullptr);
    project.CompleteProject();
    EXPECT_THROW(project.CompleteProject(), InvalidContractException);
}

TEST(ProjectTest, CalculateCostUsesBudget) {
    Project project("BaseProject", 1000.0, nullptr);
    EXPECT_NO_THROW(project.CalculateCost());
    EXPECT_LE(project.GetBudget(), 1000.0);
}

TEST(BuildingProjectTest, BuildFlow) {
    BuildingProject project("House", 20000.0, nullptr);
    project.BuildFoundation();
    EXPECT_NO_THROW(project.ConstructWalls());
    project.InstallRoof();
    project.ConductFinishing();
    project.CompleteProject();
    EXPECT_TRUE(project.IsCompleted());
}

TEST(BuildingProjectTest, ConstructWallsWithoutFoundationThrows) {
    BuildingProject project("House", 20000.0, nullptr);
    EXPECT_THROW(project.ConstructWalls(), UnsafeWorkConditionException);
}

TEST(BuildingProjectTest, CalculateCostNotGreaterThanBudget) {
    BuildingProject project("House", 20000.0, nullptr);
    project.CalculateCost();
    EXPECT_LE(project.GetBudget(), 20000.0);
}

TEST(ReconstructionProjectTest, ReconstructionFlow) {
    ReconstructionProject project("OldHouse", 15000.0, nullptr);
    project.ReplaceOldMaterials();
    project.RestoreFacade();
    project.CompleteProject();
    EXPECT_TRUE(project.IsCompleted());
}

TEST(ReconstructionProjectTest, CalculateCostLessThanBudget) {
    ReconstructionProject project("OldHouse", 15000.0, nullptr);
    project.CalculateCost();
    EXPECT_LE(project.GetBudget(), 15000.0);
}

TEST(DemolitionProjectTest, RequestPermit) {
    DemolitionProject p("OldBuilding", 5000.0, nullptr);
    p.RequestPermit();
    EXPECT_NO_THROW(p.RequestPermit());
}

TEST(DemolitionProjectTest, ExecuteAfterPermitMarksCompleted) {
    DemolitionProject p("OldBuilding", 5000.0, nullptr);
    p.RequestPermit();
    p.CompleteProject();
    EXPECT_TRUE(p.IsCompleted());
}

