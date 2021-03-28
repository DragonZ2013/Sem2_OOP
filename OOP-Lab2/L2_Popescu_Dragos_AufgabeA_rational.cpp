#include "L2_Popescu_Dragos_AufgabeA_rational.h"
#include <exception>
#include <iostream>

Rational::Rational(int num, int den) 
{//checks for div 0
    if (den != 0) {
        numerator = num;
        denominator = den;
    }
    else 
		throw std::exception();
    
}

Rational::Rational() 
{//constructor without value
    numerator=0;
    denominator=1;
    
}

int Rational::get_numerator() 
{//getter for numerator
    return numerator;
}

void Rational::set_numerator(int value) 
{//setter for numerator
    numerator = value;
}

int Rational::get_denominator() 
{//getter for denominator
    return denominator;
}

void Rational::set_denominator(int value) 
{//setter for denominator (checks for div 0)
    if (value != 0) 
        denominator = value;
    else
        throw std::exception();
}

Rational Rational::operator + (Rational other) 
{//adds 2 Rational types with operator(infix)
    return add(other);
}

Rational Rational::operator * (Rational other) 
{//multiply 2 Rational types with operator(infix)
    return multiply(other);
}

Rational Rational::operator - (Rational other) 
{//subtract 2 Rational types with operator(infix)
    return subtract(other);
}

Rational Rational::operator / (Rational other) 
{//divide 2 Rational types with operator(infix)
    return divide(other);
}

Rational Rational::add(Rational other)
{//adds 2 Rational types(prefix)
    if(other.denominator==0||denominator==0)
        throw std::exception();//checks for div 0
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    Rational newRational = Rational(newNumerator, newDenominator);
    return newRational;
}


Rational Rational::multiply (Rational other) 
{//multiply 2 Rational types(prefix)
    if(other.denominator==0||denominator==0)
        throw std::exception();//checks for div 0
    int newNumerator = numerator  * other.numerator ;
    int newDenominator = denominator * other.denominator;
    Rational newRational = Rational(newNumerator, newDenominator);
    return newRational;
}

Rational Rational::subtract (Rational other) 
{//subtract 2 Rational types(prefix)
    if(other.denominator==0||denominator==0)
        throw std::exception();//checks for div 0
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    Rational newRational = Rational(newNumerator, newDenominator);
    return newRational;
}

Rational Rational::divide (Rational other) 
{//divide 2 Rational types(prefix)
    if(other.numerator==0||denominator==0)
        throw std::exception();//checks for div 0
    int newNumerator = numerator  * other.denominator ;
    int newDenominator = denominator * other.numerator;
    Rational newRational = Rational(newNumerator, newDenominator);
    return newRational;
}

void Rational::inverse ()
{//inverts the fraction(throws exception on numerator = 0)
    if(numerator==0)
        throw std::exception();
    int aux=numerator;
    numerator=denominator;
    denominator=aux;
}

int Rational::compare (Rational other)
{//returns 1 if this>other, returns 0 if this==other, returns -1 if this<other
    if(other.denominator==0||denominator==0)
        throw std::exception();
    double val_this = double(numerator)/denominator;
    double val_other = double(other.numerator)/other.denominator;
    if(val_this>val_other)
        return 1;
    if(val_this==val_other)
        return 0;
    return -1;
}

int gcd(int a, int b) 
{//greatest common divisor
    if(!b)
        return a;
    return gcd(b, a%b); 
}

void Rational::reduce()
{//divides the values by the greatest common divisor (if it's already reduced div by 1)
    int temp = gcd(numerator,denominator);
    numerator/=temp;
    denominator/=temp;
}

void Rational::operator += (Rational other) 
{//adds the other element to the first, modifying the first
    if(other.denominator==0||denominator==0)
        throw std::exception();//checks for div 0
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    numerator=newNumerator;
    denominator=newDenominator;
}

void Rational::print_rational()
{//print function for Rational type
    std::cout<<numerator<<"/"<<denominator<<'\n';
}
Rational::~Rational(){
//no allocs with "new"
}