#include "Domain.h"

Cars::Cars(int new_id,string new_model,string new_mark,int new_year,int new_km,double new_price,string new_performance,string new_fuel)
{
    id=new_id;
    model=new_model;
    mark=new_mark;
    year_first_reg=new_year;
    km=new_km;
    price=new_price;
    performance=new_performance;
    fuel=new_fuel;
}

int Cars::Get_id()
{
    return id;
}

string Cars::Get_model()
{
    return model;
}

string Cars::Get_mark()
{
    return mark;
}

int Cars::Get_year()
{
    return year_first_reg;
}

int Cars::Get_km()
{
    return km;
}

double Cars::Get_price()
{
    return price;
}

string Cars::Get_performance()
{
    return performance;
}

string Cars::Get_fuel()
{
    return fuel;
}

void Cars::Set_id(int new_id)
{
    id=new_id;
}

void Cars::Set_model(string new_model)
{
    model=new_model;
}

void Cars::Set_mark(string new_mark)
{
    mark=new_mark;
}

void Cars::Set_year(int new_year)
{
    year_first_reg=new_year;
}

void Cars::Set_km(int new_km)
{
    km=new_km;
}

void Cars::Set_price(double new_price)
{
    price=new_price;
}

void Cars::Set_performance(string new_performance)
{
    performance=new_performance;
}

void Cars::Set_fuel(string new_fuel)
{
    fuel=new_fuel;
}
