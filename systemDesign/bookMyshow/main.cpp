
#include "theater.h"
#include "user.h"

int Theater::idCounter = 0;
int Ticket::idCounter = 0;
int Show::idCounter = 0;
int User::idCounter = 0;
int main(){

    GuestUser *piyush = new GuestUser("Piyush");
    RegisteredUser *ayush = new RegisteredUser("Ayush");
    RegisteredUser *saurabh = new RegisteredUser("Saurabh");

    Movie *ironMan = new Movie("Iron Man", Language::ENGLISH, Genre::ACTION);
    Movie *avengers = new Movie("Avengers: End Game", Language::ENGLISH, Genre::ACTION);
    Movie *walkToRemember = new Movie("The Walk To Remember", Language::ENGLISH, Genre::ROMANCE);
    Movie *housefull = new Movie("HouseFull 2", Language::HINDI, Genre::COMEDY);


    Theater *pvr_gip = new Theater("PVR","GIP Noida",30);
    Theater *big_cinema = new Theater("Big Cinema","Sector 137 Noida",40);
    Show *show1 = new Show(time(0),ironMan,pvr_gip);

    Show *show2 = new Show(time(0),housefull,pvr_gip);


}