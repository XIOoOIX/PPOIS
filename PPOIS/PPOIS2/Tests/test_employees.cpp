#include <gtest/gtest.h>
#include "../Employees/Engineer.h"
#include "../Employees/Worker.h"
#include "../Employees/Accountant.h"
#include "../Employees/Manager.h"
#include "../Projects/Project.h"
#include "../Employees/Supplier.h"
#include "../Materials/Material.h"
#include "../Exceptions/Exceptions.h"
#include "../Places/Warehouse.h"

TEST(EmployeeTest, WorkOnNullProjectThrows) {
    Employee e("Emp", "Pos", 1000.0);
    EXPECT_THROW(e.WorkOnProject(nullptr), ProjectNotFoundException);
}

TEST(EmployeeTest, DismissMakesInactive) {
    Employee e("Emp", "Pos", 1000.0);
    e.Dismiss();
    EXPECT_FALSE(e.IsActive());
}

TEST(EngineerTest, ApproveWithoutBlueprintThrows) {
    Engineer e("Eng", 50000);
    EXPECT_THROW(e.ApproveBlueprint(), InvalidBlueprintException);
}

TEST(EngineerTest, CreateAndApproveBlueprint) {
    Engineer e("Eng", 50000);
    e.CreateBlueprint();
    EXPECT_NO_THROW(e.ApproveBlueprint());
}

TEST(WorkerTest, WorkOnProjectNoThrow) {
    Worker worker("Worker", 30000, "concrete");
    Project project("House", 1000.0, nullptr);
    EXPECT_NO_THROW(worker.WorkOnProject(&project));
}

TEST(AccountantTest, PayEmployeeNullThrows) {
    Accountant a("Acc", 70000);
    EXPECT_THROW(a.PayEmployee(nullptr, 1000.0), EmployeeNotFoundException);
}

TEST(AccountantTest, PayEmployeeNegativeThrows) {
    Accountant a("Acc", 70000);
    Worker w("Worker", 30000, "concrete");
    EXPECT_THROW(a.PayEmployee(&w, -1.0), InvalidPaymentException);
}


TEST(SupplierTest, ConstructorSetsCorrectValues) {
    Supplier supplier("Иван Сидоров", 60000.0, 15.0);
    EXPECT_EQ(supplier.GetName(), "Иван Сидоров");
    EXPECT_EQ(supplier.GetDeliveredMaterials(), 0);
}


TEST(SupplierTest, DeliverMaterialNullThrows) {
    Supplier supplier("Иван Сидоров", 60000.0);
    EXPECT_THROW(supplier.DeliverMaterial(nullptr), MaterialNotFoundException);
}


TEST(SupplierTest, CheckStockEmptyReturnsFalse) {
    Supplier supplier("Иван Сидоров", 60000.0);
    EXPECT_FALSE(supplier.CheckStock());
}


TEST(SupplierTest, WorkOnProjectNullThrows) {
    Supplier supplier("Иван Сидоров", 60000.0);
    EXPECT_THROW(supplier.WorkOnProject(nullptr), ProjectNotFoundException);
}


TEST(SupplierTest, GetDeliveredMaterialsReturnsCorrectCount) {
    Supplier supplier("Иван Сидоров", 60000.0,100);
    Warehouse w ("1","2",1200,100);
    Material mat("1", 1.0, 2.0);
    supplier.DeliverMaterial(&mat,&w);
    EXPECT_EQ(supplier.GetDeliveredMaterials(), 1);
}

TEST(ManagerTest, AssignTaskNullThrows) {
    Manager m("Man", 60000);
    EXPECT_THROW(m.AssignTask(nullptr), EmployeeNotFoundException);
}

TEST(ManagerTest, AssignTaskToWorker) {
    Manager m("Man", 60000);
    Worker w("Worker", 30000, "concrete");
    EXPECT_NO_THROW(m.AssignTask(&w));
}