#pragma once
#include <vector>
#include "Domain.h"

class Repository
{
private:
vector<Cars> car_array;
int id_new_elem;
public:
Repository();
int GetSize();
vector<Cars> GetArray();
int PosById(int find_id);
void AddCarToRepo(string new_model,string new_mark,int new_year,int new_km,double new_price,string new_performance,string new_fuel);//gives its own id
void EditAllCar(int find_id,string new_model,string new_mark,int new_year,int new_km,double new_price,string new_performance,string new_fuel);
void RemoveCarFromRepo(int find_id);
/*
void EditCarModel(int find_id,string new_model);
void EditCarMark(int find_id,string new_mark);
void EditCarYear(int find_id,int new_year);
void EditCarKm(int find_id,int new_km);
void EditCarPrice(int find_id,double new_price);
void EditCarPerformance(int find_id, string new_performance);//temp
void EditCarFuel(int find_id,string new_fuel);*/
//to-do move to Controller
vector<Cars> RetCarsByModel(string search_model);//exact search
vector<Cars> RetCarsByMark(string search_mark);//exact search
vector<Cars> RetCarsByAge(int search_age);//less than
vector<Cars> RetCarsByKm(int search_km);//less than
vector<Cars> RetCarsSortedByPrice();

};