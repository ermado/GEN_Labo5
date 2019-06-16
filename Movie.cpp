#include "Movie.h"

/***************************************************************************************************
 * MainClass Implementations
 **************************************************************************************************/


Movie::Movie( const std::string& title) : _title( title ) {}

std::string Movie::getTitle() const { return _title; }


/***************************************************************************************************
 * SubClass Implementations
 **************************************************************************************************/


RegularMovie::RegularMovie(const std::string& title) : Movie(title) {}

inline double RegularMovie::getAmount(int daysRented) const {
    double amount = movieTypeBaseAmount[REGULAR];
    if (daysRented > movieTypeDayLimit[REGULAR])
        amount += (daysRented - movieTypeDayLimit[REGULAR]) * BASETAX;
    return amount;
}

inline int RegularMovie::getRenterPoints() const {
    return 1;
}



NewReleaseMovie::NewReleaseMovie(const std::string& title) : Movie(title) {}

inline double NewReleaseMovie::getAmount(int daysRented) const {
    return daysRented * movieTypeBaseAmount[NEW_RELEASE];
}

inline int NewReleaseMovie::getRenterPoints() const {
    return 2;
}



ChildrenMovie::ChildrenMovie(const std::string& title) : Movie(title) {}

inline double ChildrenMovie::getAmount(int daysRented) const {
    double amount = movieTypeBaseAmount[CHILDRENS];
    if (daysRented > movieTypeDayLimit[CHILDRENS])
        amount += (daysRented - movieTypeDayLimit[CHILDRENS]) * BASETAX;
    return amount;

}

inline int ChildrenMovie::getRenterPoints() const {
    return 1;
}

