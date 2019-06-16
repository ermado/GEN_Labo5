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


TEST(StatementTestWMock, CanGetCorrectTotalFrequentPoints) {


    MockRegularMovie movie;// = new MockRegularMovie();
    EXPECT_CALL(movie, getRenterPoints()).WillRepeatedly(Return(20));
    EXPECT_CALL(movie, getTitle()).WillRepeatedly(Return("Babar"));
    EXPECT_CALL(movie, getAmount(10)).WillRepeatedly(Return(50));

    Rental rt(&movie,10);
    EXPECT_EQ( rt.toString(movie.getAmount(10)), "Babar\t50\n");



}