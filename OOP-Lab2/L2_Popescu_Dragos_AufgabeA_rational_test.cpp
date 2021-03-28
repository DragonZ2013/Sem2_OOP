#include <iostream>
#include <cassert>
#include "L2_Popescu_Dragos_AufgabeA_rational.h"

using namespace std;


void TestsInitialise()
{//tests the Rational constructor method
    std::cout<<"Tests Initialise...\n";
    try {//test b denominator = 0 (initialize error)
        Rational a = Rational(1,0);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test b denominator = 0 (initialize error)
        Rational a = Rational(15,0);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test 1/1 success
        Rational a = Rational(1,1);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test both = 0 (initialize error)
        Rational a = Rational(0,0);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test numerator = 0 success
        Rational a = Rational(0,1);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Initialise Succes!\n";
}

void TestsMultiply()
{//tests the Rational multiply(*) method
    std::cout<<"Tests Multiply...\n";
    try {//test b denominator = 0 (initialize error)
        Rational a = Rational(0,1);
        Rational b = Rational(1,0);
        a=a*b;
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test 0*0
        Rational a = Rational(0,1);
        Rational b = Rational(0,2);
        a=a*b;
        assert(a.get_numerator()==0&&a.get_denominator()==2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test all positive
        Rational a = Rational(7,3);
        Rational b = Rational(21,12);
        a=a*b;
        assert(a.get_numerator()==147&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test 0*big number
        Rational a = Rational(0,3);
        Rational b = Rational(1231231,12);
        a=a*b;
        assert(a.get_numerator()==0&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test negative numerator * positive numerator;positive denominator*negative denominator
        Rational a = Rational(-1,3);
        Rational b = Rational(1231231,-12);
        a=a*b;
        assert(a.get_numerator()==-1231231&&a.get_denominator()==-36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test negative numerator * positive numerator;positive denominator*negative denominator
        Rational a = Rational(1,-3);
        Rational b = Rational(-1231231,12);
        a=a*b;
        assert(a.get_numerator()==-1231231&&a.get_denominator()==-36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test all negative
        Rational a = Rational(-1,-3);
        Rational b = Rational(-1231231,-12);
        a=a*b;
        assert(a.get_numerator()==1231231&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Multiply Success!\n";
}

void TestsAdd()
{//tests the Rational add(+) method
    std::cout<<"Tests Add...\n";
    try {//test b denominator = 0 (initialize error)
        Rational a = Rational(0,1);
        Rational b = Rational(1,0);
        a=a+b;
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test 0+0
        Rational a = Rational(0,1);
        Rational b = Rational(0,2);
        a=a+b;
        assert(a.get_numerator()==0&&a.get_denominator()==2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test  all positive
        Rational a = Rational(7,3);
        Rational b = Rational(21,12);
        a=a+b;
        assert(a.get_numerator()==147&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test 0 + big number
        Rational a = Rational(0,3);
        Rational b = Rational(1231231,12);
        a=a+b;
        assert(a.get_numerator()==3693693&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//tests both negative - big number
        Rational a = Rational(-2,-3);
        Rational b = Rational(1231231,12);
        a=a+b;
        assert(a.get_numerator()==-3693717&&a.get_denominator()==-36);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Add Success!\n";
}

void TestsSubtract()
{//tests the Rational subtract(-) method
    std::cout<<"Tests Subtract...\n";
    try {//test b denominator=0 (initialize error)
        Rational a = Rational(0,1);
        Rational b = Rational(1,0);
        a=a-b;
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test 0-0
        Rational a = Rational(0,1);
        Rational b = Rational(0,2);
        a=a-b;
        assert(a.get_numerator()==0&&a.get_denominator()==2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test all positive
        Rational a = Rational(7,3);
        Rational b = Rational(21,12);
        a=a-b;
        assert(a.get_numerator()==21&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test 0-big number
        Rational a = Rational(0,3);
        Rational b = Rational(1231231,12);
        a=a-b;
        assert(a.get_numerator()==-3693693&&a.get_denominator()==36);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test both negative - big number
        Rational a = Rational(-2,-3);
        Rational b = Rational(1231231,12);
        a=a-b;
        assert(a.get_numerator()==3693669&&a.get_denominator()==-36);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Subtract Success!\n";
}


void TestsDivision()
{//tests the Rational division(/) method
    std::cout<<"Tests Division...\n";
    try {//test b denominator = 0 (initialize error)
        Rational a = Rational(0,1);
        Rational b = Rational(1,0);
        a=a/b;
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test b numerator=0
        Rational a = Rational(0,1);
        Rational b = Rational(0,2);
        a=a/b;
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test both positive
        Rational a = Rational(7,3);
        Rational b = Rational(21,12);
        a=a/b;
        assert(a.get_numerator()==84&&a.get_denominator()==63);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test numerator a = 0
        Rational a = Rational(0,3);
        Rational b = Rational(1231231,12);
        a=a/b;
        assert(a.get_numerator()==0&&a.get_denominator()==3693693);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test both negative / both positive
        Rational a = Rational(-2,-3);
        Rational b = Rational(1231231,12);
        a=a/b;
        assert(a.get_numerator()==-24&&a.get_denominator()==-3693693);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Division Success!\n";
}

void TestsInverse()
{//tests the Rational inverse method
    std::cout<<"Tests Inverse...\n";
    try {//test both negative
        Rational a = Rational(-2,-3);
        a.inverse();
        assert(a.get_numerator()==-3&&a.get_denominator()==-2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test denominator positive,numerator=0
        Rational a = Rational(0,1);
        a.inverse();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test denominator negative,numerator=0
        Rational a = Rational(0,-127);
        a.inverse();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {//test big numbers
        Rational a = Rational(123131,23131);
        a.inverse();
        assert(a.get_numerator()==23131&&a.get_denominator()==123131);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Inverse Success!\n";
}

void TestsReduce()
{//tests the Rational reduce method
        std::cout<<"Tests Reduce...\n";
    try {//test both positive
        Rational a = Rational(2,4);
        a.reduce();
        assert(a.get_numerator()==1&&a.get_denominator()==2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test numerator=0
        Rational a = Rational(0,1);
        a.reduce();
        assert(a.get_numerator()==0&&a.get_denominator()==1);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test denominator negative
        Rational a = Rational(2,-4);
        a.reduce();
        assert(a.get_numerator()==1&&a.get_denominator()==-2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test numerator negative
        Rational a = Rational(-2,4);
        a.reduce();
        assert(a.get_numerator()==1&&a.get_denominator()==-2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test both negative
        Rational a = Rational(-2,-4);
        a.reduce();
        assert(a.get_numerator()==1&&a.get_denominator()==2);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test denominator=0
        Rational a = Rational(1,0);
        a.reduce();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    std::cout<<"Tests Reduce Success!\n";
}

void TestsCompare()
{//tests the Rational compare method
    std::cout<<"Tests Compare...\n";
    try {//test initialise error
        Rational a = Rational(1,0);
        Rational b = Rational(2,1);
        int res = a.compare(b);
        assert(false);
    }
    catch (exception& e) {
        assert(true);
    }
    try {//test a<b
        Rational a = Rational(1,2);
        Rational b = Rational(2,1);
        int res=a.compare(b);
        assert(res == -1);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test a==b
        Rational a = Rational(4,2);
        Rational b = Rational(2,1);
        int res=a.compare(b);
        assert(res == 0);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test a>b
        Rational a = Rational(6,2);
        Rational b = Rational(2,1);
        int res=a.compare(b);
        assert(res == 1);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Tests Compare Success!\n";
}

void TestsSetter()
{//tests the Rational setter method
    std::cout<<"Tests Setter...\n";
    try {//test numerator=0
        Rational a = Rational(6,2);
        a.set_numerator(0);
        a.set_denominator(1);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }
    try {//test denominator=0
        Rational a = Rational(6,2);
        a.set_numerator(1);
        a.set_denominator(0);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    std::cout<<"Tests Setter Success!\n";
}

void runTests()
{//runs all the test functions
    TestsInitialise();
    TestsMultiply();
    TestsAdd();
    TestsSubtract();
    TestsDivision();
    TestsInverse();
    TestsReduce();
    TestsCompare();
    TestsSetter();
}

Rational add_array(Rational x[],int nr_el)
{
    Rational sum=x[0];
    for(int i=1;i<nr_el;i++)
        sum+=x[i];
    sum.reduce();
    return sum;
}

void create_add_array()
{
    Rational arr[100]={Rational(1,2),Rational(2,1),Rational(3,4),Rational(1,4),Rational(7,2),Rational(4,8)};
    int nr_el=6;
    Rational res=add_array(arr,nr_el);
    res.print_rational();
}

int main() {
    runTests();
    create_add_array();
    return 0;
}
