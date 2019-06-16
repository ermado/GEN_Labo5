// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>


/*
 * On a pris la decision d'implementer de cette facon les attributs des calculs des taxes (et
 * non comme attribut de classes) afin d'avoir dans le meme lieu toutes les "constantes" de base
 * liés aux calculs des prix pour une meilleure et plus rapide gestion. Sous forme d'enum, chaque
 * type de fil à accés aux constantes via sa position dans les autres tableaux
 */
#define BASETAX 1.5
enum movieType {REGULAR, NEW_RELEASE, CHILDRENS};
static double movieTypeBaseAmount[] = {2, 3, 1.5};
static double movieTypeDayLimit[] = {2, 0, 3};
static int movieTypeRenterPoints[] = {1, 2, 1};

/***************************************************************************************************
 * MainClass
 **************************************************************************************************/

class Movie {
public:

    explicit Movie(const std::string& title);
    std::string getTitle() const;
    virtual double getAmount(int daysRented) const = 0;
    virtual int getRenterPoints() const = 0;

private:
    std::string _title;
};


/***************************************************************************************************
 * SubClasses
 **************************************************************************************************/


class RegularMovie : public Movie {

public:
    explicit RegularMovie(const std::string& title);
    double getAmount(int daysRented) const override;
    int getRenterPoints() const override;

};

class NewReleaseMovie : public Movie {

public:
    explicit NewReleaseMovie(const std::string& title);
    double getAmount(int daysRented) const override;
    int getRenterPoints() const override;

};

class ChildrenMovie : public Movie {

public:
    explicit ChildrenMovie(const std::string& title);
    double getAmount(int daysRented) const override;
    int getRenterPoints() const override;

};





#endif // MOVIE_H