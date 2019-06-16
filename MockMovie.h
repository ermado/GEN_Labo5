#ifndef GEN_LABO5_MOCKMOVIE_H
#define GEN_LABO5_MOCKMOVIE_H

#include "gmock/gmock.h"
#include "Movie.h"


/**
 * Ona crée ces classes afin de tester avec mocking mais on a pas reussi à les utiliser mais on
 * a pas reussi à resoudre les problemes inehernt à leur implementation à temps (utiliser
 * une quelqconque de ces methodes produit un stackdup)
 *
 */
class MockMovie : public Movie {
public:

    MOCK_METHOD1(setTitle, std::string(void()));
    MOCK_CONST_METHOD0(getTitle, std::string());
    MOCK_CONST_METHOD0(getRenterPoints, int());
    MOCK_CONST_METHOD1(getAmount, double(int));


};



#endif //GEN_LABO5_MOCKMOVIE_H
