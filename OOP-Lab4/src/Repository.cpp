#pragma once
#include "Controller.h"

Repository::Repository()
{
    size=0;
}

int Repository::Get_Size()
{
    return size;
}

vector<Fruits> Repository::Get_Arr()
{
    return arr;
}

int Repository::Pos_Fruit(string name)
{
    for(int i=0;i<size;i++)
        if(arr[i].get_name()==name)
            return i;
    return -1;
}

void Repository::Add_Fruit(string name)
{
    int pos=Pos_Fruit(name);
    if(pos==-1)
    {
        Fruits new_fruit = Fruits(name,"default_origin","1970-01-01",0.0);
        arr.push_back(new_fruit);
        size++;
    }
    else
        arr[pos].add_elements(1);    
}

void Repository::Add_Fruit_Object(Fruits new_fruit)
{
    arr.push_back(new_fruit);
    size++;
}

void Repository::Edit_Fruit_Origin(string name,string new_origin)
{
    int pos=Pos_Fruit(name);
    if(pos==-1)
    {
        throw exception();
    }
    else
    {
        arr[pos].set_origin(new_origin);
    }  
}

void Repository::Edit_Fruit_Date(string name,string new_date)
{
    int pos=Pos_Fruit(name);
    if(pos==-1)
    {
        throw exception();
    }
    else
    {
        arr[pos].set_date(new_date);
    }  
}

void Repository::Edit_Fruit_Price(string name,string new_price)
{
    int pos=Pos_Fruit(name);
    if(pos==-1)
    {
        throw exception();
    }
    else
    {
        arr[pos].set_price(stod(new_price));
    }  
}

void Repository::Remove_Fruit(string name)
{
    int pos=Pos_Fruit(name);
    if(pos==-1)
    {
        throw exception();
    }
    else
    {
        arr[pos].remove_elements(1);
        if(arr[pos].get_quantity()==0)
        {
            arr.erase(arr.begin()+pos);
            size--;
        }
    } 
}

void Repository::Print_Arr()
{
    for(int i=0;i<size;i++)
        arr[i].Print_Fruit();
}
/*
Controller Repository::point() const {
	return Controller(*this);
}*/