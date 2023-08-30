#ifndef BOOKMYSHOW_H
#define BOOKMYSHOW_H

#include <vector>
#include <map>
#include <string>

using namespace std;

#include "theater.h"

class BookMyShow {
    vector<Theater*> theaters;
    static map<string, vector<Show*>> movieMap;

    void generateMovieMap() {
        for (Theater* theater : theaters) {
            vector<Show*> showArray = theater->getShows();
            for (Show* show : showArray) {
                if (show != nullptr) {
                    if (movieMap.count(show->getMovie()->getName())) {
                        movieMap[show->getMovie()->getName()].push_back(show);
                    }
                    else {
                        vector<Show*> movieShowList;
                        movieShowList.push_back(show);
                        movieMap[show->getMovie()->getName()] = movieShowList;
                    }
                }
            }
        }
    }

public:
    BookMyShow(vector<Theater*> theaters) : theaters(theaters) {
        generateMovieMap();
    }

    static vector<Show*> searchShows(string movieName) {
        if (movieMap.count(movieName)) {
            return movieMap[movieName];
        }
        else {
            return {};
        }
    }
};

#endif