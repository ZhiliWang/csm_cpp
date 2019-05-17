/*------------------<CIS 278 Assignment 9>----------------
    * Student: Zhili Wang
    * Due Date: Oct 15th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: a9_1.cpp
    * Description: utilizing class and a series of fraction
                   operations (set, arithmetic, boolean,
                   output)
---------------------------------------------------------*/

#include <iostream>

using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        void set(int, int);
        Fraction addedTo(Fraction);
        Fraction subtract(Fraction);
        Fraction multipliedBy(Fraction);
        Fraction dividedBy(Fraction);
        bool isEqualTo(Fraction);
        void print();
};






/*-----------------------Functions------------------------
    set: setting up 2 input integers as a fraction
---------------------------------------------------------*/
    void Fraction::set(int numer, int denom) {
        numerator = numer;
        denominator = denom;
    }






/*-----------------------Functions------------------------
    addedTo: add the fraction object with another input
             fraction object
---------------------------------------------------------*/
    Fraction Fraction::addedTo(Fraction frac) {
        Fraction tempFrac;

        if (denominator == frac.denominator) {
            tempFrac.numerator = numerator + frac.numerator;
            tempFrac.denominator = denominator;

        } else {
            tempFrac.denominator = denominator * frac.denominator;
            tempFrac.numerator = numerator * frac.denominator
                                 + frac.numerator * denominator;
        }

        return tempFrac;
    }






/*-----------------------Functions------------------------
    subtract: subtract the input fraction object from the
              fraction object
---------------------------------------------------------*/
    Fraction Fraction::subtract(Fraction frac) {
        Fraction tempFrac;
        double valFraction = numerator/denominator;
        double valFrac = frac.numerator/frac.denominator;

        if (valFraction == valFrac) {
            tempFrac.numerator = 0;
            tempFrac.denominator = 0;

        } else if (denominator == frac.denominator) {
            tempFrac.numerator = numerator - frac.numerator;
            tempFrac.denominator = denominator;

        } else {
            tempFrac.denominator = denominator * frac.denominator;
            tempFrac.numerator = numerator * frac.denominator
                                 - frac.numerator * denominator;
        }

        return tempFrac;
    }





/*-----------------------Functions------------------------
    multipliedBy: multiply the fraction object with another
                  input fraction object
---------------------------------------------------------*/
    Fraction Fraction::multipliedBy(Fraction frac) {
        Fraction tempFrac;

        tempFrac.numerator = numerator * frac.numerator;
        tempFrac.denominator = denominator * frac.denominator;

        return tempFrac;
    }






/*-----------------------Functions------------------------
    dividedBy: divide the input fraction object by the
               fraction object
---------------------------------------------------------*/
    Fraction Fraction::dividedBy(Fraction frac) {
        Fraction tempFrac;

        tempFrac.numerator = numerator * frac.denominator;
        tempFrac.denominator = denominator * frac.numerator;

        return tempFrac;
    }






/*-----------------------Functions------------------------
    isEqualTo: check if the fraction object is equal to
               the input object
---------------------------------------------------------*/
    bool Fraction::isEqualTo(Fraction frac) {
        double valFraction = numerator/denominator;
        double valFrac = frac.numerator/frac.denominator;

        return (valFraction == valFrac);
    }






/*-----------------------Functions------------------------
    print: print and output the fraction object
---------------------------------------------------------*/
    void Fraction::print() {
        cout << numerator << "/" << denominator;
    }






/*-----------------------Functions------------------------
    main: running the client program
---------------------------------------------------------*/
int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}






/*--------------------------Output------------------------
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.

Process finished with exit code 0
---------------------------------------------------------*/