#include "Repository.h"
#include <exception>
#include <algorithm>

bool Compare_Price(Cars x,Cars y)
{
    return(x.Get_price()<y.Get_price());
}

Repository::Repository()
{
    id_new_elem=0;
}

int Repository::GetSize()
{
    return car_array.size();
}

vector<Cars> Repository::GetArray()
{
    return car_array;
}

void Repository::AddCarToRepo(string new_model,string new_mark,int new_year,int new_km,double new_price,string new_performance,string new_fuel)
{
    Cars new_car=Cars(id_new_elem,new_model,new_mark,new_year,new_km,new_price,new_performance,new_fuel);
    id_new_elem++;
    car_array.push_back(new_car);
}

int Repository::PosById(int find_id)
{
    for(int i=0;i<car_array.size();i++)
    {
        if(car_array[i].Get_id()==find_id)
            return i;
    }
    return -1;
}

void Repository::RemoveCarFromRepo(int find_id)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array.erase(car_array.begin()+pos);
}

/*
void Repository::EditCarModel(int find_id,string new_model)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_model(new_model);
}

void Repository::EditCarMark(int find_id,string new_mark)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_mark(new_mark);
}

void Repository::EditCarYear(int find_id,int new_year)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_year(new_year);
}

void Repository::EditCarKm(int find_id,int new_km)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_km(new_km);
}

void Repository::EditCarPrice(int find_id,double new_price)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_price(new_price);
}

void Repository::EditCarPerformance(int find_id,string new_performance)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_performance(new_performance);
}

void Repository::EditCarFuel(int find_id,string new_fuel)
{
    int pos=PosById(find_id);
    if(pos==-1)
        throw exception();
    else
        car_array[pos].Set_fuel(new_fuel);
}
*/
//to-do move to Controller
vector<Cars> Repository::RetCarsSortedByPrice()
{
    vector<Cars> temp_output= car_array;
    sort(temp_output.begin(),temp_output.end(),Compare_Price);

    return temp_output;
}


vector<Cars> Repository::RetCarsByModel(string search_model)
{
    vector<Cars> temp_output;
    for(int i=0;i<car_array.size();i++)
        if (car_array[i].Get_model() == search_model)
            temp_output.push_back(car_array[i]);
    
    return temp_output;
}


vector<Cars> Repository::RetCarsByMark(string search_mark)
{
    vector<Cars> temp_output;
    for(int i=0;i<car_array.size();i++)
        if (car_array[i].Get_mark() == search_mark)
            temp_output.push_back(car_array[i]);
    
    return temp_output;
}


vector<Cars> Repository::RetCarsByAge(int search_age)
{
    vector<Cars> temp_output;
    for(int i=0;i<car_array.size();i++)
        if (2021-car_array[i].Get_year() <= search_age)
            temp_output.push_back(car_array[i]);
    
    return temp_output;
}


vector<Cars> Repository::RetCarsByKm(int search_km)
{
    vector<Cars> temp_output;
    for(int i=0;i<car_array.size();i++)
        if (car_array[i].Get_km() <= search_km)
            temp_output.push_back(car_array[i]);
    
    return temp_output;
}