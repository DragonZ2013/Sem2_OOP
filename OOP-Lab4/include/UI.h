#pragma once
#include "Controller.h"

class UI
{
private:
    Controller cont;
public:

    UI(Controller &cont_other);//constructor for controller

    bool Check_Date_Valid(string s);//checks if a string is a valid date format

    bool Check_Double_Valid(string s);//checks if a string is convertable to double

    bool Check_Int_Valid(string s);//checks if a string is convertable to int

    void MainMenu();//the main menu, calls the UI loop

    void Lots_Of_Newlines();//newlines for prettier UI

    void Read_Add_String();//console read for adding elements

    void Read_Edit_String();//console read for editing elements

    void Read_Delete_String();//console read for removing elements

    void Print_FilterByName(string substr);//prints list filtered by name

    void Print_FilterByQuantity(int less_than);//prints list filtered by quantity

    void Print_SortByExpDate();//prints list sorted by expiration date


};