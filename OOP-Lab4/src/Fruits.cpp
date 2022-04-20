#include "Fruits.h"

Fruits::Fruits(string new_name,string new_origin,string new_exp_date,double new_price)
{
    name=new_name;
    origin=new_origin;
    exp_date=new_exp_date;//yyyy-mm-dd
    quantity=1;
    price=new_price;
}
Fruits::Fruits(string new_name,string new_origin,string new_exp_date,double new_price,int new_quantity)
{
    name=new_name;
    origin=new_origin;
    exp_date=new_exp_date;//yyyy-mm-dd
    quantity=new_quantity;
    price=new_price;
}
string Fruits::get_name()
{
    return name;
}
void Fruits::set_name(string new_name)
{
    name=new_name;
}
string Fruits::get_origin()
{
    return origin;
}
void Fruits::set_origin(string new_origin)
{
    origin=new_origin;
}
string Fruits::get_date()
{
    return exp_date;
}
void Fruits::set_date(string new_date)
{
    exp_date=new_date;
}
int Fruits::get_quantity()
{
    return quantity;
}
void Fruits::set_quantity(int new_quantity)
{
    quantity=new_quantity;
}
void Fruits::add_elements(int count)
{
    quantity+=count;
}
void Fruits::remove_elements(int count)
{
    if(count>quantity)
        throw exception();
    quantity-=count;
}
double Fruits::get_price()
{
    return price;
}
void Fruits::set_price(double new_price)
{
    price=new_price;
}

void Fruits::Print_Fruit()
{
    cout<<name<<" "<<origin<<" "<<exp_date<<" "<<quantity<<" "<<price<<"\n";
}
Fruits::~Fruits()
{

}