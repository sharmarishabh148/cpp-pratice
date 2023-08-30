#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

#include "enum.h"

using namespace std;

class Movie {
private:
    string name;
    float ratings = 0.0;
    Language language;
    Genre genre;

public:
    Movie(string name, Language language, Genre genre) :
        name(name), language(language), genre(genre) {}

    string getName() const {
        return name;
    }

    float getRatings() const {
        return ratings;
    }

    Language getLanguage() const {
        return language;
    }

    Genre getGenre() const {
        return genre;
    }
};

#endif