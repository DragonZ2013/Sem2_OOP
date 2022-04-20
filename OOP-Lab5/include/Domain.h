#pragma once
#include <string>
using namespace std;
class Cars
{
private:
    int id;//unique
    string model;
    string mark;
    int year_first_reg;
    int km;//double?
    double price;
    string performance;//replace with int
    string fuel;
public:
    Cars(int new_id,string new_model,string new_mark,int new_year,int new_km,double new_price,string new_performance,string new_fuel);
    int Get_id();
    string Get_model();
    string Get_mark();
    int Get_year();
    int Get_km();
    double Get_price();
    string Get_performance();//temp
    string Get_fuel();
    void Set_id(int new_id);
    void Set_model(string new_model);
    void Set_mark(string new_mark);
    void Set_year(int new_year);
    void Set_km(int new_km);
    void Set_price(double new_price);
    void Set_performance(string new_performance);//temp
    void Set_fuel(string new_fuel);

};