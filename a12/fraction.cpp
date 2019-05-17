/*------------------<CIS 278 Assignment 12>------------------
    * Student: Zhili Wang
    * Due Date: Nov 7th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: fraction.cpp
    * The Fraction class has two integer variables:
      numerator and a denominator (cannot be 0 and enforced
      by the assert function of cassert header file).
      Fraction objects are simplified and stored as in their
      "most simplified forms". When we get improper fractions
      as results, an overloaded insertion operator ("<<")
      converts them to mixed fractions.
-----------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include "fraction.h"
using namespace std;






namespace cs_fraction {






    Fraction::Fraction(int varNumerator, int varDenominator) {
        assert(varDenominator != 0);
        numerator = varNumerator;
        denominator = varDenominator;
        simplify();
    }






    Fraction operator + (const Fraction &left, const Fraction &right) {
        Fraction answer;

        answer.denominator = left.denominator * right.denominator;
        answer.numerator = left.numerator * right.denominator
                           + right.numerator * left.denominator;
        answer.simplify();

        return answer;
    }






    Fraction operator - (const Fraction &left, const Fraction &right) {
        Fraction answer;

        answer.denominator = left.denominator * right.denominator;
        answer.numerator = left.numerator * right.denominator
                           - right.numerator * left.denominator;
        answer.simplify();

        return answer;
    }






    Fraction operator * (const Fraction &left, const Fraction &right) {
        Fraction answer;

        answer.numerator = left.numerator * right.numerator;
        answer.denominator = left.denominator * right.denominator;
        answer.simplify();

        return answer;
    }






    Fraction operator / (const Fraction &left, const Fraction &right) {
        Fraction answer;

        answer.numerator = left.numerator * right.denominator;
        answer.denominator = left.denominator * right.numerator;
        answer.simplify();

        return answer;
    }







    Fraction Fraction::operator += (const Fraction &right) {
        *this = *this + right;

        return *this;
    }






    Fraction Fraction::operator -= (const Fraction &right) {
        *this = *this - right;

        return *this;
    }






    Fraction Fraction::operator *= (const Fraction &right) {
        *this = *this * right;

        return *this;
    }






    Fraction Fraction::operator /= (const Fraction &right) {
        *this = *this / right;

        return *this;
    }






    bool operator < (const Fraction &left, const Fraction &right) {
        return (left.numerator * right.denominator
                < right.numerator * left.denominator);
    }






    bool operator <= (const Fraction &left, const Fraction &right) {
        return (left.numerator * right.denominator
                <= right.numerator * left.denominator);
    }






    bool operator > (const Fraction &left, const Fraction &right) {
        return (left.numerator * right.denominator
                > right.numerator * left.denominator);
    }






    bool operator >= (const Fraction &left, const Fraction &right) {
        return (left.numerator * right.denominator
                >= right.numerator * left.denominator);
    }






    bool operator == (const Fraction &left, const Fraction &right) {
        return (left.numerator * right.denominator
                == right.numerator * left.denominator);
    }






    bool operator != (const Fraction &left, const Fraction &right) {
        return (left.numerator * right.denominator
                != right.numerator * left.denominator);
    }






    Fraction Fraction::operator ++ () {
        numerator += denominator;

        return *this;
    }






    Fraction Fraction::operator ++ (int) {
        Fraction tempFrac(numerator, denominator);
        numerator += denominator;

        return tempFrac;
    }






    Fraction Fraction::operator -- () {
        numerator -= denominator;

        return *this;
    }






    Fraction Fraction::operator -- (int) {
        Fraction tempFrac(numerator, denominator);
        numerator -= denominator;

        return tempFrac;
    }






    ostream &operator << (ostream &out, const Fraction &obj) {
        Fraction tempFrac;
        tempFrac.numerator = obj.numerator;
        tempFrac.denominator = obj.denominator;

        if (tempFrac.denominator == 1) {
            out << tempFrac.numerator;

        } else if (abs(tempFrac.numerator) > tempFrac.denominator) {
            int whole = tempFrac.numerator / tempFrac.denominator;
            tempFrac.numerator = abs(tempFrac.numerator % tempFrac.denominator);

            if (tempFrac.numerator == 0) {
                out << whole;

            } else {
                out << whole << "+" << tempFrac.numerator << "/" << tempFrac.denominator;
            }
        } else {
            out << tempFrac.numerator << "/" << tempFrac.denominator;
        }

        return out;
    }






    istream &operator >> (istream &strm, Fraction &obj) {
        int dummy;
        strm >> dummy;
        if (isspace(strm.peek())) {
            obj.numerator = dummy;

        } else if (strm.peek() == '/') {
            strm.ignore();
            obj.numerator = dummy;
            strm >> obj.denominator;

        } else if (strm.peek() == '+') {
            strm.ignore();
            strm >> obj.numerator;

            if (dummy < 0 && strm.peek() == '/') {
                strm.ignore();
                strm >> obj.denominator;
                obj.numerator = dummy * obj.denominator - obj.numerator;

            } else if (dummy > 0 && strm.peek() == '/') {
                strm.ignore();
                strm >> obj.denominator;
                obj.numerator = dummy * obj.denominator + obj.numerator;
            }
        }

        obj.simplify();
        return strm;
    }

/*-----------------<Private Member Function>-----------------
    void Fraction::simplify()

    - The private simplify() member function test every prime
    number as a common divisor/factor between the numerator
    and denominator of the calling fraction object to its
    simplest form.
    - it starts off by comparing numerator and denominator,
    because with common divisors, the "simplifying" process
    stops once the smaller value (between numerator and
    denominator) is completely simplified.
    - the function ensures that denominator is never negative.

-----------------------------------------------------------*/

 void Fraction::simplify() {
        if (numerator == 0) {
            denominator = 1;
        }

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }

        int tempIter;
        if (abs(numerator) <= abs(denominator)) {
            tempIter = abs(numerator);

        } else if (abs(numerator) > abs(denominator)) {
            tempIter = abs(denominator);
        }

        for (int i = 2; i <= tempIter; i++) {
            while (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
            }
        }
    }
}