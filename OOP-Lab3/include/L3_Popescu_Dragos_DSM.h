#pragma once
#include <string>
#include <vector>
typedef int TWeight;//template for Weight
using namespace std;

class DSM
{
private:

    int elem_count;
    vector<string> elem_names;
    int **weight_matrix; 

public:

    DSM(int elementCount);

    DSM(vector<string> element_names);

    DSM(const DSM &other);

    int size();

    void set_element_name(int index, string name);

    string get_name(int index);

    int get_index(string name);

    void add_link(string from_element, string to_element, TWeight weight);

    void delete_link(string from_element,string to_element);

    bool have_link(string from_element,string to_element);//renamed to_link to to_element

    int link_weight(string from_element, string to_element);//renamed to_link to to_element

    int count_to_links(string element_name);

    int count_from_links(string element_name);

    int count_all_links();

    double calculate_matrix_density();

    void print_matrix();

    ~DSM();
};