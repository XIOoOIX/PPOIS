Accountant 1 4 → Employee, Project
Apartment 2 4 → Building
Brick 2 3 → Material
Building 6 7 → Material, Project
Branch 6 9 → Employee, Project
BuildingProject 3 6 → Project, Client
Bytovka 2 5 → Building
Client 6 8 → Project, Contract, Payment
Company 9 13 → Branch, Project, Employee, Client, Contract, Payment, Warehouse
Concrete 1 5 → Material
Contract 5 8 → Client, Project
Crane 2 5 → Vehicle
DemolitionProject 3 6 → Project, Client
Drill 1 4 → Tool
Employee 5 7 → Project
Engineer 1 4 → Employee, Project
Equipment 4 7 → 
House 3 5 → Building
Manager 1 5 → Employee, Project
Material 4 8 →
MeasuringTool 1 3 → Tool
Payment 5 8 → Client, Contract
Place 4 6 → 
Project 11 11 → Client, Employee, Material, Equipment, Place
ReconstructionProject 3 6 → Project, Client
ReflectiveVest 1 4 → Workwear
ShoppingMall 3 4 → Building
Site 3 6 → Place, Project, Equipment
Steel 2 4 → Material
SteelConstruction 2 4 → Building
Supplier 3 6 → Employee, Material, Project, Warehouse
Tool 2 5 → Equipment
Truck 2 5 → Vehicle
Vehicle 2 6 → Equipment
Wood 1 4 → Material
Worker 1 4 → Employee, Project
Workwear 3 4 → Equipment
Warehouse 2 5 → Place, Material

InvalidPaymentException 0 1
NotEnoughFundsException 0 1
EmployeeNotFoundException 0 1
ProjectNotFoundException 0 1
MaterialNotFoundException 0 1
InvalidContractException 0 1
EquipmentOverloadException 0 1
UnsafeWorkConditionException 0 1
InvalidBlueprintException 0 1
InvalidAccessException 0 1
OutOfStockException 0 1
WarehouseCapacityException 0 1
