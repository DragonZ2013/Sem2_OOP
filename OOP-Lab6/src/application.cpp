#include "UI.h"
#include "Controller.h"
#include "Repo.h"
#include "Cars.h"
#include <iostream>
#include "Error.h"
#include <cassert>
using namespace::std;


void run_application() {
    //CrudRepository<Domain::Car> *cr;
    Repository::Repo r;
    Repository::UserRepo ur;
    //cr = &r;
    Service::Controller c(r,ur);
    c.read_in_cars();
    std::cout<<c.get_car_list().size();
    //c.initialise_cars();
    //c.read_in_cars();
    UI::Console con(c);
    con.run_console();
}

int main() {
	//Team AG17 Popescu Dragos-Septimiu,Postescu Razvan
    //persistency File input/output
    //run_application();
    cout<<"OOP/tPruf:\nClass"<<endl;
    return 0;
}