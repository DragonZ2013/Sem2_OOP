#include <iostream>
#include <cassert>
#include "L3_Popescu_Dragos_DSM.h"
using namespace std;


void runTests_intConstructor()
{
    
    try{
        DSM dsm_fail = DSM(-2);
        assert(false);
    }
    catch(exception&){
        assert(true);
    };
    try{
        DSM dsm_fail2 = DSM(0);
        dsm_fail2.calculate_matrix_density();
        assert(false);
    }
    catch(exception&){
        assert(true);
    };
    DSM dsm = DSM(4);

    dsm.set_element_name(0,"Auto");
    dsm.set_element_name(1,"Motor");
    //dsm.add_link("Motor","Kupplung",1);
    dsm.set_element_name(2,"Getriebe");
    dsm.set_element_name(3,"Raeder");
    dsm.set_element_name(4,"Sitze");
    dsm.set_element_name(5,"Kupplung");
    dsm.set_element_name(6,"Test");
    assert(dsm.size() == 7);
    assert(dsm.get_index("Auto")==0);
    assert(dsm.get_index("Motor")==1);

    dsm.add_link("Motor","Kupplung",1);
    dsm.add_link("Kupplung","Getriebe",1);
    dsm.add_link("Getriebe","Raeder",2);
    dsm.add_link("Tueren","Auto",2);
    dsm.add_link("Auto","Tueren",2);
    assert(dsm.size()==8);
    assert(dsm.count_from_links("Motor")==1);
    dsm.add_link("Kupplung","Motor",5);
    assert(dsm.size() == 8);

    assert(dsm.get_name(7) == "Tueren");
    assert(dsm.have_link("Kupplung","Motor"));
    assert(dsm.count_all_links()==6);
    assert(dsm.count_from_links("Sitze")==0);
    try{
        dsm.count_from_links("Inexisting")==0;
        assert(false);
    }
    catch(exception&){
        assert(true);
    };
    assert(dsm.count_from_links("Motor") == 1);
    //dsm.print_matrix();
}

void runTests_vectorConstructor()
{
    vector <string> vec_input;
    vec_input.push_back("Auto");
    vec_input.push_back("Motor");
    vec_input.push_back("Getriebe");
    vec_input.push_back("Raeder");
    DSM dsm = DSM(vec_input);
    dsm.set_element_name(4,"Sitze");
    dsm.set_element_name(5,"Kupplung");
    dsm.set_element_name(6,"Test");
    assert(dsm.size() == 7);
    assert(dsm.get_index("Auto")==0);
    assert(dsm.get_index("Motor")==1);

    dsm.add_link("Motor","Kupplung",1);
    dsm.add_link("Kupplung","Getriebe",1);
    dsm.add_link("Getriebe","Raeder",2);
    dsm.add_link("Tueren","Auto",2);
    dsm.add_link("Auto","Tueren",2);
    assert(dsm.size()==8);
    assert(dsm.count_from_links("Motor")==1);
    dsm.add_link("Kupplung","Motor",5);
    assert(dsm.size() == 8);

    assert(dsm.get_name(7) == "Tueren");
    assert(dsm.have_link("Kupplung","Motor"));
    assert(dsm.count_all_links()==6);
    assert(dsm.count_from_links("Sitze")==0);
    try{
        dsm.count_from_links("Inexisting")==0;
        assert(false);
    }
    catch(exception&){
        assert(true);
    };
    assert(dsm.count_from_links("Motor") == 1);
}

void runTests_copyConstructor()
{
    vector <string> vec_input;
    vec_input.push_back("Auto");
    vec_input.push_back("Motor");
    vec_input.push_back("Getriebe");
    vec_input.push_back("Raeder");
    DSM dsm_string = DSM(vec_input);
    DSM dsm = dsm_string;
    dsm.set_element_name(4,"Sitze");
    dsm.set_element_name(5,"Kupplung");
    dsm.set_element_name(6,"Test");
    assert(dsm.size() == 7);
    assert(dsm.get_index("Auto")==0);
    assert(dsm.get_index("Motor")==1);

    dsm.add_link("Motor","Kupplung",1);
    dsm.add_link("Kupplung","Getriebe",1);
    dsm.add_link("Getriebe","Raeder",2);
    dsm.add_link("Tueren","Auto",2);
    dsm.add_link("Auto","Tueren",2);
    assert(dsm.size()==8);
    assert(dsm.count_from_links("Motor")==1);
    dsm.add_link("Kupplung","Motor",5);
    assert(dsm.size() == 8);

    assert(dsm.get_name(7) == "Tueren");
    assert(dsm.have_link("Kupplung","Motor"));
    assert(dsm.count_all_links()==6);
    assert(dsm.count_from_links("Sitze")==0);
    try{
        dsm.count_from_links("Inexisting")==0;
        assert(false);
    }
    catch(exception&){
        assert(true);
    };
    assert(dsm.count_from_links("Motor") == 1);
}

int main() 
{
    runTests_intConstructor();
    runTests_vectorConstructor();
    runTests_copyConstructor();
    return 0;
}
