/*------------------<CIS 278 Assignment 13>----------------
    * Student: Zhili Wang
    * Due Date: Nov 14th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: mystring.h
    * Implementing mystring class header file
---------------------------------------------------------*/

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring {
    class MyString {
        private:
            char* description;

        public:
            MyString();
            MyString(const char* inDesc);
            MyString(const MyString& copyString);
            ~ MyString();
            int length() const;

            MyString& operator = (const MyString& copyAssign);

            char operator [] (int index) const;
            char& operator[] (int index);

            friend std::ostream &operator << (std::ostream &out, const MyString &source);
            friend bool operator < (const MyString &left, const MyString &right);
            friend bool operator <= (const MyString &left, const MyString &right);
            friend bool operator > (const MyString &left, const MyString &right);
            friend bool operator >= (const MyString &left, const MyString &right);
            friend bool operator == (const MyString &left, const MyString &right);
            friend bool operator != (const MyString &left, const MyString &right);
    };
}

#endif



/*-------------------------< Output >------------------------

 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z

 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

 ----- Testing relational operators between MyStrings
 Comparing app to apple
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing apple to
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing  to Banana
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing Banana to Banana
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false

 ----- Testing relations between MyStrings and char *
 Comparing he to hello
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing why to wackity
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true

 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is Binky
 val is winky
 after assign,  val is Binky

 Program ended with exit code: 0
-----------------------------------------------------------*/
