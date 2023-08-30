#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <ctime>
#include <iostream>

#include "enum.h"
#include "movie.h"
#include "user.h"
#include "theater.h"

using namespace std;

class Theater;

class Show
{
private:
    static int idCounter;
    int id;
    std::time_t showTime;
    Movie* movie;
    Theater* theater;
    int availableSeats;

public:
    Show() = delete;
    Show(std::time_t showTime,  Movie* movie, Theater* theater)
    {
        idCounter += 1;
        this->id = idCounter;
        this->showTime = showTime;
        this->movie = movie;
        this->theater = theater;
        this->availableSeats = 0;//theater->getCapacity();
        //theater->getShows().push_back(this);
    }

    Movie* getMovie() {
        return movie;
    }
    void setTheater(Theater* theater) {
        this->theater = theater;
    }
    void setAvailableSeats(int availableSeats) {
        this->availableSeats = availableSeats;
    }
    int getAvailableSeats() {
        return availableSeats;
    }
    void updateShow(){
    }

    Ticket* bookTicket(RegisteredUser user, int seats){
        // use mutex here
        if(availableSeats >= seats && seats >0){
            Ticket *ticket = new Ticket();
            availableSeats -= seats;
            ticket->setOwner(user.getName());
            ticket->setBookedShow(this);
            ticket->setBookingTime(time(0));
            ticket->setNumberOfSeats(seats);
            cout <<"Successfully booked";
            user.bookingHistory.push_back(*ticket);
            return ticket;
        }
        else{
            cout <<"Seats not Available";
            return NULL;
        }
    }

    string toString() {

        string build;
        build= "Show{" + 
                /*"id=" + to_string(id) +
                //", showTime=" + std::asctime(std::localtime(&showTime)) +
                ", movie=" + movie->getName() +
                ", theater=" + theater->getName() +
                ", availableSeats=" + to_string(availableSeats)  +*/
                '}';
        return build;
    }
};

#endif