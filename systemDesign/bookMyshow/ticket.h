#ifndef TICKET_H
#define TICKET_H

#include <ctime>
#include <string>

#include "enum.h"
#include "show.h"

using namespace std;

class Show;

class Ticket {
private:
    static int idCounter;
    int id;
    string owner;
    time_t bookingTime;
    int numberOfSeats;
    Show* bookedShow;

public:
    Ticket() {
        idCounter += 1;
        this->id = idCounter;
    }

    string getTicketInfo() {
        return "";
    }

    int cancelTicket() {
        return 0;
    }

    string getOwner() const {
        return owner;
    }

    void setOwner(const string& owner) {
        this->owner = owner;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    time_t getBookingTime() const {
        return bookingTime;
    }

    void setBookingTime(time_t bookingTime) {
        this->bookingTime = bookingTime;
    }

    int getNumberOfSeats() const {
        return numberOfSeats;
    }

    void setNumberOfSeats(int numberOfSeats) {
        this->numberOfSeats = numberOfSeats;
    }

    Show* getBookedShow() const {
        return bookedShow;
    }

    void setBookedShow(Show* bookedShow) {
        this->bookedShow = bookedShow;
    }

    string toString() {
        return "Ticket{" +
                /*"owner=" + owner + '\'' +
                ", bookingTime=" + std::asctime(std::localtime(&bookingTime)) +
                ", numberOfSeats=" + numberOfSeats +
                ", bookedShow=" + bookedShow +*/
                to_string('}');
    }
};

#endif
