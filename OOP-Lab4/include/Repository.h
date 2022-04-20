#pragma once
#include "Fruits.h"
//#include "Controller.h"
#include <vector>

class Repository
{
private:
    vector<Fruits> arr;
    int size;
public:

    Repository();//constructor

    int Get_Size();//getter for array size

    vector<Fruits> Get_Arr();//getter for array

    int Pos_Fruit(string name);//searches for position of fruit, -1 if doesn't exist

    void Add_Fruit(string name);//adds a fruit to the list(either new element or increases quantity)

    void Add_Fruit_Object(Fruits new_fruit);//adds a fruit object(primarily for main)

    void Remove_Fruit(string name);//remove fruit from the list(delete or decrease quantity)

    void Edit_Fruit_Origin(string name,string new_origin);//changes the fruit origin
    
    void Edit_Fruit_Date(string name,string new_date);//changes the fruit expiration date

    void Edit_Fruit_Price(string name,string new_price);//changes the fruit price

    void Print_Arr();//prints the entire array

    //Controller point() const;

};