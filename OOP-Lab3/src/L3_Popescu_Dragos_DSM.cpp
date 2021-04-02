#include "L3_Popescu_Dragos_DSM.h"
#include <exception>
#include <iostream>
//#include <cstring>

DSM::DSM(int elemCount)
{//constructor for int input,throws exception for negative values
	//elem_names=vector <string>(elemCount);
	//elem_count=elem_names.size();
	if(elemCount<0)
	throw exception();
	elem_count=elemCount;
	weight_matrix = new int*[elem_count];
	for(int i=0;i<elem_count;i++)
	{
		weight_matrix[i]=new int[elem_count];
		elem_names.push_back("temp");
	}
	
	for(int i=0;i<elem_count;i++)
		for(int j=0;j<elem_count;j++)
			weight_matrix[i][j]=0;
}


DSM::DSM(vector<string> element_names)
{//constructor for vector<string> input
	elem_names=element_names;
	elem_count=elem_names.size();
	weight_matrix = new int*[elem_count];
	for(int i=0;i<elem_count;i++)
		weight_matrix[i]=new int[elem_count];
	
	for(int i=0;i<elem_count;i++)
		for(int j=0;j<elem_count;j++)
			weight_matrix[i][j]=0;
}

DSM::DSM(const DSM &other)
{//constructor by copying 
	elem_names=other.elem_names;
	elem_count=other.elem_count;
	weight_matrix=other.weight_matrix;
}

void DSM::set_element_name(int index,string name)
{//sets the name of an element by index, also handles resizing
	
	if(index>=elem_count)
	{	
		for(int i=elem_count;i<=index;i++)
			elem_names.push_back("temp");
		int new_elem_count=index+1;
		int **new_weight_matrix;
		new_weight_matrix = new int*[new_elem_count+1];
		for(int i=0;i<new_elem_count;i++)
			new_weight_matrix[i]=new int[new_elem_count+1];
		for(int i=0;i<new_elem_count;i++)
			for(int j=0;j<new_elem_count;j++)
				if(i<elem_count&&j<elem_count)
					new_weight_matrix[i][j]=weight_matrix[i][j];
				else
					new_weight_matrix[i][j]=0;
		weight_matrix=new_weight_matrix;
		elem_count=new_elem_count;
		
	}
		elem_names[index]=name;
}

int DSM::size()
{//returns the size of the string vector
	return elem_count;
}

string DSM::get_name(int index)
{//gets the string based on index
	return elem_names[index];
}

int DSM::get_index(string name)
{//gets the index based on string
	//char *char_temp1,*char_temp2;
	//strcpy(char_temp1,name.c_str());
	for(int i=0;i<elem_count;i++)
	{
		//strcpy(char_temp2,elem_names[i].c_str());
		//if(!strcmp(char_temp1,char_temp2))
		if(name==elem_names[i])
			return i;
	}
	return -1;
}

void DSM::add_link(string from_element,string to_element,int weight)
{//adds links between 2 element, also requests resize if either/both do not exist
	
	int from_index=get_index(from_element);
	int to_index=get_index(to_element);

	if(from_index==-1)
	{
		from_index=elem_count;
		set_element_name(from_index,from_element);
	}
	if(to_index==-1)
	{
		to_index=elem_count;
		set_element_name(to_index,to_element);
	}
	
	weight_matrix[from_index][to_index]=weight;
}

void DSM::delete_link(string from_element,string to_element)
{//sets the weight of a link to 0, throws exception if either/both do not exist
	
	int from_index=get_index(from_element);
	int to_index=get_index(to_element);
	if(from_index==-1||to_index==-1)
		throw exception();
	weight_matrix[from_index][to_index]=0;
}

int DSM::link_weight(string from_element,string to_element)
{//returns the weight value of a link from->to element, throws exception if either/both do not exist
	int from_index=get_index(from_element);
	int to_index=get_index(to_element);
	if(from_index==-1||to_index==-1)
		throw exception();
	return weight_matrix[from_index][to_index];
}

int DSM::count_from_links(string element_name)
{//counts the amount of non-weight0 links from the element, throws exception if element does not exist
	int from_index=get_index(element_name);
	if(from_index==-1)
		throw exception();
	int ret=0;
	for(int i=0;i<elem_count;i++)
		if(weight_matrix[from_index][i])
			ret++;
	return ret;
}

int DSM::count_to_links(string element_name)
{//counts the amount of non-weight0 links to the element, throws exception if element does not exist
	int to_index=get_index(element_name);
	if(to_index==-1)
		throw exception();
	int ret=0;
	for(int i=0;i<elem_count;i++)
		if(weight_matrix[i][to_index])
			ret++;
	return ret;
}

bool DSM::have_link(string from_element,string to_element)
{//returns wether the weight value of a link from->to element is non-0, throws exception if either/both do not exist
	int from_index=get_index(from_element);
	int to_index=get_index(to_element);
	if(from_index==-1||to_index==-1)
		throw exception();
	if(weight_matrix[from_index][to_index])
		return true;
	return false;
}

int DSM::count_all_links()
{//counts all non-0 weights from the matrix
	int ret=0;
	for(int i=0;i<elem_count;i++)
		for(int j=0;j<elem_count;j++)
			if(weight_matrix[i][j])
				ret++;
	return ret;
}

double DSM::calculate_matrix_density()
{//returns the density of non-0 weights the matrix as a double (between 1 and 0)
	if(elem_count<=0)
		throw exception();
	double count=count_all_links(),val=elem_count*elem_count;
	return count/val;
}

void DSM::print_matrix()
{//function for printing matrix, first line = vector elements followed by weight_matrix
	for(int i=0;i<elem_count;i++)
		cout<<elem_names[i]<<' ';
	cout<<'\n';
	for(int i=0;i<elem_count;i++)
		{for(int j=0;j<elem_count;j++)
			cout<<weight_matrix[i][j]<<' ';
		cout<<'\n';
		}
}

DSM::~DSM()
{//deconstructor for DSM
	for(int i=0;i<elem_count;i++)
		delete weight_matrix[i];
	delete weight_matrix;
	//elem_names.clear();

}