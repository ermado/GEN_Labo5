#ifndef GEN_LABO5_MOCKSTATEMENT_H
#define GEN_LABO5_MOCKSTATEMENT_H

#include "gmock/gmock.h"
#include "statement.h"

class MockStatement : public Statement {

    MOCK_METHOD0(getFrequentRenterPoints, const int());
};

#endif //GEN_LABO5_MOCKSTATEMENT_H
