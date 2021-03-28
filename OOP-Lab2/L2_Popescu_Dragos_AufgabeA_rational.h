#pragma once
class Rational {

private:
    int numerator;
    int denominator;
    //double doesn't make sense for reduce/by the definition of rational numbers!
    //double=rational number => rational = rational/rational

public:
    Rational(int num, int den);

    Rational();

    int get_numerator();

    int get_denominator();

    void set_numerator(int value);  

    void set_denominator(int value);

    Rational add(Rational other);

    Rational subtract(Rational other);

    Rational multiply(Rational other);
    
    Rational divide(Rational other);

    Rational operator +(Rational other); 

    Rational operator *(Rational other);

    Rational operator -(Rational other);

    Rational operator /(Rational other);

    void operator +=(Rational other);

    void reduce();

    void inverse();

    int compare(Rational other);

    void print_rational();

    //Destructor
    ~Rational();
};