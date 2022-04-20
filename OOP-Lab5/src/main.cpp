#include <iostream>
#include "Domain.h"
#include "Repository.h"
#include <iostream>
using namespace std;
void print_vector(vector<Cars> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].Get_id()<<' '<<vec[i].Get_model()<<' '<<vec[i].Get_mark()<<' '<<vec[i].Get_year()<<' '<<vec[i].Get_km()<<' '<<vec[i].Get_price()<<' '<<vec[i].Get_performance()<<' '<<vec[i].Get_fuel()<<'\n';
	}
}

int main()
{
	Repository repo;
	repo.AddCarToRepo("Octavia","Skoda",2001,20123,50000.5,"perf1","diesel");
	repo.AddCarToRepo("Solentza","Dacia",1999,40567,10000.4,"pref2","gas");
	repo.AddCarToRepo("CyberTruck","Tesla",2019,100,100000.2,"pref3","electric");
	repo.AddCarToRepo("Junk","Mobile",1987,40,500,"perf4","diesel");
	print_vector(repo.RetCarsSortedByPrice());
	repo.RemoveCarFromRepo(2);
	print_vector(repo.RetCarsByAge(23));
}

