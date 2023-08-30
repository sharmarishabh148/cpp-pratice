#ifndef THEATER_H
#define THEATER_H

#include <vector>
#include <string>

#include "show.h"

using namespace std;

class Theater {
private:
    static int idCounter;
    int id;
    string name;
    string location;
    int capacity;
    vector<Show*> shows;

public:
    Theater(string name, string location, int capacity) :
        name(name), location(location), capacity(capacity) {
        idCounter += 1;
        this->id = idCounter;
        shows.reserve(1);
    }

    void updateShow(Show* oldShow, Show* newShow) {
        // some code here
    }

    vector<Show*> getShows() {
        return shows;
    }

    string getName() {
        return name;
    }

    int getCapacity() {
        return capacity;
    }
};


#endif