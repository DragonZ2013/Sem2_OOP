#include "Controller.h"
#include <algorithm>

bool CompareDate(Fruits x,Fruits y){
    return (x.get_date()<y.get_date());
}

bool CompareName(Fruits x,Fruits y){
    return (x.get_name()<y.get_name());
}

Controller::Controller(Repository &other_repo) : repo(other_repo)
{

}

bool Controller::Is_Valid_Name(string str)
{
    if(repo.Pos_Fruit(str)==-1)
        return false;
    return true;
}

void Controller::Add_To_Repo(string str)
{
    repo.Add_Fruit(str);
}

void Controller::Remove_From_Repo(string str)
{
    if(!Is_Valid_Name(str))
        throw exception();
    repo.Remove_Fruit(str);
}

void Controller::Print_All()
{
    repo.Print_Arr();
}

void Controller::Edit_Origin(string str_name,string str_new_origin)
{
    repo.Edit_Fruit_Origin(str_name,str_new_origin);
}

void Controller::Edit_Date(string str_name,string str_new_date)
{
    repo.Edit_Fruit_Date(str_name,str_new_date);
}

void Controller::Edit_Price(string str_name,string str_new_price)
{
    repo.Edit_Fruit_Price(str_name,str_new_price);
}

vector<Fruits> Controller::FilterByQuantity(int less_than)
{
    vector<Fruits> temp_input= repo.Get_Arr();
    vector<Fruits> temp_output;
    int temp_size=repo.Get_Size();
    for(int i=0;i<temp_size;i++)
        if (temp_input[i].get_quantity() < less_than)
            temp_output.push_back(temp_input[i]);
    
    return temp_output;
}

vector<Fruits> Controller::FilterByName(string substr)
{
    vector<Fruits> temp_input= repo.Get_Arr();
    vector<Fruits> temp_output;
    int temp_size=repo.Get_Size();
    for(int i=0;i<temp_size;i++)
        if (temp_input[i].get_name().find(substr) != std::string::npos)
            temp_output.push_back(temp_input[i]);
    sort(temp_output.begin(),temp_output.end(),CompareName);
    return temp_output;
}

vector<Fruits> Controller::SortByExpDate()
{
    vector<Fruits> temp_output= repo.Get_Arr();
    int temp_size=repo.Get_Size();
    sort(temp_output.begin(),temp_output.end(),CompareDate);

    return temp_output;
}