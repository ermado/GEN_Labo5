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

/**
 * Test de la fonction processRentals de Statement.h
 * Dans notre idee, on voulait tester cette classe de cette facon, mais le push_back de *rental
 * ne focntionne pas correctement. Cause le manque de temps pour trouver une solution cette faille,
 * on a ete donc on obbligé à commenter ce test et tester les differents elements d'una eutre facon
 */
/*TEST(StatementTestWMock, CanGetCorrectTotalFrequentPoints) {

    MockCustomer customer;
    auto* rental = new MockRental();
    auto* rentalList = new std::vector<MockRental>;
    auto* movie = new MockRegularMovie();

    EXPECT_CALL(*movie, getRenterPoints()).WillRepeatedly(Return(20));
    EXPECT_CALL(*movie, getTitle()).WillRepeatedly(Return("Babar"));
    EXPECT_CALL(*movie, getAmount(10)).WillRepeatedly(Return(50));

    EXPECT_CALL(*rental, getMovie()).WillRepeatedly(ReturnPointee(movie));
    EXPECT_CALL(*rental, getDaysRented()).WillRepeatedly(Return(10));

    rentalList->push_back(*rental);
    EXPECT_CALL(customer, getRentals()).WillRepeatedly(ReturnPointee(rentalList));

    Statement statement(&customer);
    EXPECT_EQ(statement.toString(), "Babar\t50\n");

}*/

