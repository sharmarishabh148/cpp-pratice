#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "ticket.h"

using namespace std;
class User {
  private:
    static int idCounter;
    int id;
    std::string name;

  public:
    User(std::string name) : id(++idCounter), name(name) {}

    std::string getName() {
      return name;
    }
};


class GuestUser : public User {
  public:
    GuestUser(string name) : User(name) {}

    void registerUser(string username, string password) {}
};


class RegisteredUser : public User {
    public:

    vector<Ticket> bookingHistory;

    RegisteredUser(string name): User(name) {}

    void cancelTicket(Ticket ticket)
    {} 
};

#endif