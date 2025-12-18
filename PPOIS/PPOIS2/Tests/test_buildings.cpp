#include <gtest/gtest.h>
#include "../Buildings/House.h"
#include "../Buildings/Bytovka.h"
#include "../Buildings/ShoppingMall.h"
#include "../Exceptions/Exceptions.h"

TEST(BuildingTest, ConstructAndInspect) {
    Building b("Addr", 100.0, 2);
    EXPECT_NO_THROW(b.BuildFoundation());
    EXPECT_NO_THROW(b.Construct());
    EXPECT_TRUE(b.IsCompleted());
}

TEST(BuildingTest, DoubleConstructThrows) {
    Building b("Addr", 100.0, 2);
    b.Construct();
    EXPECT_THROW(b.Construct(), InvalidAccessException);
}

TEST(BuildingTest, PaintDoesNotThrow) {
    Building b("Addr", 100.0, 2);
    EXPECT_NO_THROW(b.Paint("white"));
}

