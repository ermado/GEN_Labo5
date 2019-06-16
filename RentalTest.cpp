#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer.h"
#include "MockMovie.h"
#include "MockRental.h"
#include "MockCustomer.h"
#include "MockStatement.h"
#include "Statement.h"

using ::testing::Return;
using ::testing::ReturnPointee;

TEST(RentalTestWRegularMovie, toStringTest) {

    Rental rental(new RegularMovie("Babar"), 20);
    EXPECT_EQ(rental.toString(50), "\tBabar\t50\n");

}