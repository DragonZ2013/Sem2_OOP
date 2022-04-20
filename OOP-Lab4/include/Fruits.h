#pragma once
#include <string>
#include <ctime>
#include <exception>
#include <iostream>
#include <algorithm>
using namespace std;
class Fruits
{
private:
    //int id;
    string name;
    string origin;
    string exp_date;//yyyy-mm-dd
    int quantity;
    double price;
public:

    Fruits(string name,string origin,string exp_date,double price);//constructor without quantity

    Fruits(string name,string origin,string exp_date,double price,int quantity);//constructor for all parameters

    string get_name();//getter for name

    void set_name(string new_name);//setter for name

    string get_origin();//getter for origin

    void set_origin(string new_origin);//setter for origin

    void set_date(string new_date);//setter for date

    string get_date();//getter for date

    int get_quantity();//getter for quantity

    void set_quantity(int new_quantity);//setter for quantity

    void add_elements(int count);//increases the quantity of elements by count

    void remove_elements(int count);//decreases the quantity of elements by count

    double get_price();//getter for price

    void set_price(double new_price);//setter for price

    void Print_Fruit();//prints fruit type

    ~Fruits();//destructor
};