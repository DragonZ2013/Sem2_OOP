#include <iostream>
#include "Controller.h"
#include "UI.h"
#include "Fruits.h"
#include "Repository.h"

int main()
{
	cout<<"WARNING: avoid the usage of spacebar, program might behave unexpectedly\n";
	Repository rep;
	Controller cont(rep);
	UI ui(cont);
	rep.Add_Fruit_Object(Fruits("Mango","Portugal","2021-07-21",3.2,7));//1
	rep.Add_Fruit_Object(Fruits("Cherry","Spain","2021-08-16",8.43,23));//2
	rep.Add_Fruit_Object(Fruits("Apple","Romania","2021-06-14",3.2,16));//3
	rep.Add_Fruit_Object(Fruits("Orange","Guatemala","2021-07-22",4.5,12));//4
	rep.Add_Fruit_Object(Fruits("Melons","Bulgaria","2021-07-21",7.8,6));//5
	rep.Add_Fruit_Object(Fruits("Watermelons","Romania","2021-04-22",6.2,4));//6
	rep.Add_Fruit_Object(Fruits("Cars","Germany","2021-03-21",10312.2,2));//7
	rep.Add_Fruit_Object(Fruits("Potato","Ukraine","2022-06-13",5.2,2));//8
	rep.Add_Fruit_Object(Fruits("Apple1","England","2021-05-13",7.3,2));//9
	rep.Add_Fruit_Object(Fruits("Apple2","Germany","2021-03-21",18.1,2));//10
	rep.Add_Fruit_Object(Fruits("Corn2","USA","2022-07-21",21.5,2));//11
	rep.Add_Fruit_Object(Fruits("Corn1","Mexico","2023-04-21",7.82,2));//12
	ui.MainMenu();
	
	return 0;
}