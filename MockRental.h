#ifndef GEN_LABO5_MOCKRENTAL_H
#define GEN_LABO5_MOCKRENTAL_H

#include "gmock/gmock.h"
#include "Rental.h"

class MockRental : public Rental {
public:

    MOCK_CONST_METHOD0(getMovie, const Movie&());
    MOCK_CONST_METHOD0(getDaysRented, int());

};

#endif //GEN_LABO5_MOCKRENTAL_H
