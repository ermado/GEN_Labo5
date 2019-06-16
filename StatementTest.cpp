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

/**
 * Test de la fonction processRentals de Statement.h
 */
TEST(StatementTestWMock, CanGetCorrectTotalFrequentPoints) {

    MockCustomer customer;
    MockRegularMovie movie;
    customer.addRental(Rental(movie));
    Statement statement(&customer);

    EXPECT_CALL(movie, getRenterPoints()).WillRepeatedly(Return(20));
    EXPECT_CALL(movie, getTitle()).WillRepeatedly(Return("Babar"));
    EXPECT_CALL(movie, getAmount(10)).WillRepeatedly(Return(50));

    EXPECT_EQ(statement.toString(), "Babar\t50\n");

}

/**
 * Test de la fonction toString de Statement.h
 */
TEST(StatementTestWMock, CanPrintCorrectStatement) {

    MockCustomer customer;
    MockRegularMovie movie("Babar");
    customer.addRental(Rental(movie));
    Statement statement(&customer);

    EXPECT_CALL(movie, getRenterPoints()).WillRepeatedly(Return(20));
    EXPECT_CALL(movie, getTitle()).WillRepeatedly(Return("Babar"));
    EXPECT_CALL(customer, getName()).WillRepeatedly(Return("Edo"));
    EXPECT_CALL(movie, getAmount(10)).WillRepeatedly(Return(50));

    EXPECT_EQ(statement.toString(), "Rental Record for Edo\n\tBabar\t50\nAmount owed is 50\nYou earned 20 frequent renter points");
}