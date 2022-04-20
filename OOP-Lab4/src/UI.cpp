#pragma once
#include "UI.h"
#include <regex>


UI::UI(Controller &other_cont) : cont(other_cont)
{

}

bool UI::Check_Date_Valid(string s)
{
    string data_out;
    std::regex pattern("^\\d{4}[-]\\d{2}[-]\\d{2}$");
    std::smatch result;

    if(!regex_search(s, result, pattern))
        return false;
    data_out = result.str();
    int y=0,m=0,d=0;
    y=(data_out[0]-'0')*1000+(data_out[1]-'0')*100+(data_out[2]-'0')*10+(data_out[3]-'0');
    m=(data_out[5]-'0')*10+(data_out[6]-'0');
    d=(data_out[8]-'0')*10+(data_out[9]-'0');
    if(m>12)
        return false;
    if(d>31)
        return false;
    if(d==31&&(m==2||m==4||m==6||m==9||m==11))
        return false;
    if(d==30&&m==2)
        return false;
    if(y%4!=0&&m==2&&d==29)
        return false;
    return true;
}

bool UI::Check_Double_Valid(string s)
{
    if(s==""||s==".")
        return false;
    std::regex pattern("^[0-9]*[.]?[0-9]*$");
    std::smatch result;

    if(!regex_search(s, result, pattern))
        return false;

    return true;
}

bool UI::Check_Int_Valid(string s)
{
    std::regex pattern("^[0-9]+$");
    std::smatch result;

    if(!regex_search(s, result, pattern))
        return false;

    return true;
}

void UI::Lots_Of_Newlines()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void UI::Read_Add_String()
{
    string input_string_add;
    cout<<"Input the name of the new product\n";
    cin>>input_string_add;
    cont.Add_To_Repo(input_string_add);
}

void UI::Read_Delete_String()
{
    string input_string_remove;
    do{
        cout<<"Input the name of the product to remove(type \"QUIT\" to return to main menu\n";
        cin>>input_string_remove;
        if(input_string_remove=="QUIT")
            return;
        if(!cont.Is_Valid_Name(input_string_remove))
            cout<<"Invalid name, try again\n";
    }while(!cont.Is_Valid_Name(input_string_remove));

    cont.Remove_From_Repo(input_string_remove);
}

void UI::Read_Edit_String()
{
    string input_string_edit,input_string_name,input_string_edit_str;
    do{
        cout<<"Choose the product you wish to edit by name (type \"QUIT\" to return to main menu)\n";
        cin>>input_string_name;
        if(input_string_name=="QUIT")
            return;
        if(!cont.Is_Valid_Name(input_string_name))
            cout<<"Invalid product, try again\n";
    }while(!cont.Is_Valid_Name(input_string_name));
    cout<<"1. Edit origin\n2. Edit expiration date(questionable practice)\n3. Edit price\n4. Back\n\n";//Edit quantity?
    cin>>input_string_edit;
    if(input_string_edit=="1")
    {
        cout<<"Input new origin\n";
        cin>>input_string_edit_str;
        cont.Edit_Origin(input_string_name,input_string_edit_str);
    }
    else
    if(input_string_edit=="2")
    {   do{
            cout<<"Input new expiration date(format: YYYY-MM-DD)\n";
            cin>>input_string_edit_str;
            if(Check_Date_Valid(input_string_edit_str))
                cont.Edit_Date(input_string_name,input_string_edit_str);
            else
                cout<<"Invalid, input a valid date(format: YYYY-MM-DD)\n";
        }while(!Check_Date_Valid(input_string_edit_str));
    }else
    if(input_string_edit=="3")
    {
        do{
            cout<<"Input new price\n";
            cin>>input_string_edit_str;
            if(Check_Double_Valid(input_string_edit_str))
                cont.Edit_Price(input_string_name,input_string_edit_str);
            else
                cout<<"Invalid, input a valid price\n";
        }while(!Check_Double_Valid(input_string_edit_str));
    }else
    if(input_string_edit=="4")
    {

    }else
    {
        cout<<"Invalid Input\n";
        Read_Edit_String();
    }
}

void UI::Print_FilterByName(string substr)
{
    vector<Fruits> print_vector = cont.FilterByName(substr);
    for(int i=0;i<print_vector.size();i++)
        print_vector[i].Print_Fruit();
}

void UI::Print_FilterByQuantity(int less_than)
{
    vector<Fruits> print_vector = cont.FilterByQuantity(less_than);
    for(int i=0;i<print_vector.size();i++)
        print_vector[i].Print_Fruit();
}

void UI::Print_SortByExpDate()
{
    vector<Fruits> print_vector = cont.SortByExpDate();
    for(int i=0;i<print_vector.size();i++)
        print_vector[i].Print_Fruit();
}

void UI::MainMenu()
{
    string input_string;
    cout<<"1. Add product\n2. Edit product\n3. Delete product\n4. Filter products by name\n5. Filter products by quantity\n6. Sort products by expiration date\n7. Print all products\n8. Exit\n\n";
    cin>>input_string;
    //switch needs int or enum type
    if(input_string=="1")
    {
        Read_Add_String();
        MainMenu();
    }
    else
    if(input_string=="2")
    {
        Read_Edit_String();
        MainMenu();
    }else
    if(input_string=="3")
    {
        Read_Delete_String();
        MainMenu();
    }else
    if(input_string=="4")
    {
        string sub_str;
        cout<<"Enter the filter name\n";
        cin>>sub_str;
        Print_FilterByName(sub_str);
        cout<<"Type anything to continue...\n";
        cin>>sub_str;
        MainMenu();
    }else
    if(input_string=="5")
    {
        string sub_str;
        do{
            cout<<"Enter the filter quantity\n";
            cin>>sub_str;
            if(Check_Int_Valid(sub_str))
                Print_FilterByQuantity(stoi(sub_str));
            else
                cout<<"Value is not an integer, try again\n";
        }while(!Check_Int_Valid(sub_str));
        cout<<"Type anything to continue...\n";
        cin>>sub_str;
        MainMenu();
    }else
    if(input_string=="6")
    {
        string sub_str;
        Print_SortByExpDate();
        cout<<"Type anything to continue...\n";
        cin>>sub_str;
        MainMenu();
    }else
    if(input_string=="7")
    {
        string wait_str;
        cont.Print_All();
        cout<<"Type anything to continue...\n";
        cin>>wait_str;
        Lots_Of_Newlines();
        MainMenu();
    }else
    if(input_string=="8")
    {
        //break;
    }else
    {
        cout<<"Invalid Input\n";
        MainMenu();
    }
}