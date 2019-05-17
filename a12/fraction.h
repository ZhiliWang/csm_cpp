/*------------------<CIS 278 Assignment 12>----------------
    * Student: Zhili Wang
    * Due Date: Nov 7th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: fraction.h
    * Implementing Fraction class header file
---------------------------------------------------------*/

#ifndef FRACTION_H
#define FRACTION_H

/*---------------------<Member Functions>-------------------

Fraction(int varNumerator = 0, int varDenominator = 1);
    Pre-conditon:  varDenominator cannot be equal to zero.

    Post-condition:  When no parameter is specified, the calling
    fraction object is by default initialized with numerator as
    0 while denominator is 1.
    If 1 parameter is included during the constructor call,
    denominator is initialized to 1 and numerator is initialized to
    whatever varNumerator is set to.
    If 2 parameter are included, numerator is initialized to
    the value of varNumerator denominator is initialized to the
    value of varDenominator.

friend Fraction operator + (const Fraction &left, const Fraction &right);
    Post-condition: Returning a fraction object as the sum of the Fraction
    object on the left operand and the Fraction object on the right operand.

friend Fraction operator - (const Fraction &left, const Fraction &right);
    Post-condition: Returning a fraction object as the difference of the Fraction
    object on the left operand and the Fraction object on the right operand.

friend Fraction operator * (const Fraction &left, const Fraction &right);
    Post-condition: Returning a fraction object as the product of the Fraction
    object on the left operand and the Fraction object on the right operand.

friend Fraction operator / (const Fraction &left, const Fraction &right);
    Post-condition: Returning a fraction object as the quotient of the Fraction
    object on the left operand and the Fraction object on the right operand.

friend bool operator < (const Fraction &left, const Fraction &right);
    Post-condition: If the Fraction object on the left operand is less than the
    Fraction object on the right operand, the function returns true; otherwise, it
    returns false.

friend bool operator <= (const Fraction &left, const Fraction &right);
    Post-condition: If the Fraction object on the left operand is less than or
    equal to the Fraction object on the right operand, the function returns true;
    otherwise, it returns false.

friend bool operator > (const Fraction &left, const Fraction &right);
    Post-condition: If the Fraction object on the left operand is greater than the
    Fraction object on the right operand, the function returns true; otherwise, it
    returns false.


friend bool operator >= (const Fraction &left, const Fraction &right);
    Post-condition: If the Fraction object on the left operand is greater than or
    equal to the Fraction object on the right operand, the function returns true;
    otherwise, it returns false.

friend bool operator == (const Fraction &left, const Fraction &right);
    Post-condition: If the Fraction object on the left operand is equal to the
    Fraction object on the right operand, the function returns true; otherwise, it
    returns false.

friend bool operator != (const Fraction &left, const Fraction &right);
    Post-condition: If the Fraction object on the left operand is not equal to the
    Fraction object on the right operand, the function returns true; otherwise, it
    returns false.

friend std::ostream &operator << (std::ostream &out, const Fraction &right);
    Post-condition::  The calling Fraction object is displayed as a mixed fraction
    if numerator is greater than the denominator, otherwise as a proper fraction.

friend std::istream &operator >> (std::istream &in, Fraction &right);
    Pre-condition: If input is improper or proper fraction, it must be entered in the
    format of "numerator/denominator".
    If the input is a mixed fraction, it must be entered in the format of "whole-number
    + numerator/denominator."

    Post-condition: Initializing numerator and denominator

Fraction operator += (const Fraction &right);
    Post-condition: Returning a fraction object as the sum of the calling Fraction
    object and the Fraction object on the right operand.


Fraction operator -= (const Fraction &right);
    Post-condition: Returning a fraction object as the difference of the calling Fraction
    object and the Fraction object on the right operand.

Fraction operator *= (const Fraction &right);
    Post-condition: Returning a fraction object as the product of the calling Fraction
    object and the Fraction object on the right operand.

Fraction operator /= (const Fraction &right);
    Post-condition: Returning a fraction object as the quotient of the calling Fraction
    object and the Fraction object on the right operand.

Fraction operator ++ (); // prefix
    Post-condition: Returning a fraction object that is pre-incremented.
    Calling object's Fraction value is added by one before any other operation takes
    place.

Fraction operator ++ (int); // postfix
    Post-condition: Returning a fraction object that is post-incremented.
    Calling object's Fraction value is added by one before any other operation takes
    place.

Fraction operator -- (); // prefix
    Post-condition: Returning a fraction object that is pre-incremented.
    Calling object's Fraction value is subtracted by one before any other operation takes
    place.

Fraction operator -- (int); // postfix
    Post-condition: Returning a fraction object that is post-incremented.
    Calling object's Fraction value is subtracted by one before any other operation takes
    place.

*/

#include <iostream>
namespace cs_fraction {
    class Fraction {
        private:
            int numerator;
            int denominator;
            void simplify();

        public:
            Fraction(int varNumerator = 0, int varDenominator = 1);

            friend Fraction operator + (const Fraction &left, const Fraction &right);
            friend Fraction operator - (const Fraction &left, const Fraction &right);
            friend Fraction operator * (const Fraction &left, const Fraction &right);
            friend Fraction operator / (const Fraction &left, const Fraction &right);

            friend bool operator < (const Fraction &left, const Fraction &right);
            friend bool operator <= (const Fraction &left, const Fraction &right);
            friend bool operator > (const Fraction &left, const Fraction &right);
            friend bool operator >= (const Fraction &left, const Fraction &right);
            friend bool operator == (const Fraction &left, const Fraction &right);
            friend bool operator != (const Fraction &left, const Fraction &right);

            friend std::ostream &operator << (std::ostream &out, const Fraction &right);
            friend std::istream &operator >> (std::istream &in, Fraction &right);

            Fraction operator += (const Fraction &right);
            Fraction operator -= (const Fraction &right);
            Fraction operator *= (const Fraction &right);
            Fraction operator /= (const Fraction &right);

            Fraction operator ++ (); // prefix
            Fraction operator ++ (int); // postfix
            Fraction operator -- (); // prefix
            Fraction operator -- (int); // postfix
    };
}

#endif

/* Output

----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing -1/2 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
*/

