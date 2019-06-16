// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movie.h"

class Rental {
public:
    Rental(Movie *movie, int daysRented );
    Rental();

    int getDaysRented() const;
    const Movie& getMovie() const;
    std::string toString(double amount);

private:
    Movie* _movie;
    int _daysRented;
};

inline Rental::
Rental(Movie *movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return *_movie; }

inline Rental::Rental() = default;

inline std::string Rental::toString(double amount) {

    std::ostringstream result;
    result << "\t" << getMovie().getTitle() << "\t"
           << amount << "\n";

    return result.str();
}


#endif // RENTAL_H