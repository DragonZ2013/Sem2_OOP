#pragma once
#include "Repository.h"

class Controller
{
private:
    Repository &repo;

    
public:

    Controller(Repository &other_repo);//constructor for controller

    void Add_To_Repo(string str);//adds elements to repo array

    void Remove_From_Repo(string str);//removes elements from repo array

    void Print_All();//prints all elements from array

    bool Is_Valid_Name(string str);//checks if the name exists in the repo array

    void Edit_Origin(string str_name,string str_new_origin);//edits origin of the element identified by name

    void Edit_Date(string str_name,string str_new_date);//edits expiration of the element identified by name

    void Edit_Price(string str_name,string str_new_price);//edits price of the element identified by name

    vector<Fruits> FilterByQuantity(int less_than);//returns array filtered by quantity

    vector<Fruits> FilterByName(string substr);//returns array filtered by name substring and sorted by name

    vector<Fruits> SortByExpDate();//returns array sorted by expiration date



};