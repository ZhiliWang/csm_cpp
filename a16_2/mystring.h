
/*------------------<CIS 278 Assignment 7>----------------
    * File Name: a16_2.h
    * Author: Zhili Wang
    * Due Date: Dec 5th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 3
    * Description: header file that consists of myString class
---------------------------------------------------------


The MyString class is designed to make working with strings easier and less
error-prone than working with traditional null-terminated C-strings.  The client
can declare and use MyStrings freely without concern for memory management
issues or the size of the MyString.  Operations for input/output, construction,
indexing, comparison, and concatenation of MyStrings are provided.  Assignment
and copying of MyString objects is allowed.

MyString(const char* inString);
post: a MyString object is created and initialized to "inString".

MyString();
post: a MyString object is created and initialized to the empty string.

MyString(const MyString& copyMe);
post: a MyString object is created and initialized to "copyMe".

friend ostream& operator<<(ostream& out, const MyString& printMe);
pre: "out" is ready for writing.
post: The contents of "printMe" have been inserted into "out".

friend istream& operator>>(istream& in, MyString& readMe);
pre: "in" is ready for reading.  The sequence of characters read must be fewer
than 128 in number.
post: Leading whitespace in "in" has been skipped and the following sequence of
non-whitespace characters have been extracted from "in" and stored in "readMe".
Reading is terminated by the next whitespace character.

void read(istream& in, char delimeter);
pre: "in" is ready for reading.  The sequence of characters read must be fewer
than 128 in number.
post: The sequence of characters in "in", terminated by "delimiter", have been
extracted and stored in the calling object.

char operator[] (int index) const;
pre: 0 <= index < length()
post: The character at position "index" (counting from 0) has been returned.

char& operator[](int index);
pre: 0 <= index < length()
post: The character at position "index" (counting from 0) has been returned.


friend bool operator<(const MyString& left, const MyString& right);
post: true is returned if left < right; false otherwise.

friend bool operator>(const MyString& left, const MyString& right);
post: true is returned if left > right; false otherwise.

friend bool operator<=(const MyString& left, const MyString& right);
post: true is returned if left <= right; false otherwise.

friend bool operator>=(const MyString& left, const MyString& right);
post: true is returned if left >= right; false otherwise.

friend bool operator==(const MyString& left, const MyString& right);
post: true is returned if left == right; false otherwise.

friend bool operator!=(const MyString& left, const MyString& right);
post: true is returned if left != right; false otherwise.

MyString operator=(const MyString& right);
post: A copy of "right" is stored in the calling object.

friend MyString operator+(const MyString& left, const MyString& right);
post: the concatenation of left and right is returned.

MyString operator+=(const MyString& right);
post: the concatenation of left and right is assigned to left and returned.

int length() const;
post: the number of characters in the calling object is returned.

*/

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

namespace cs_mystring {
    class MyString {
    public:
        MyString(const char* inString);
        MyString();
        MyString(const MyString& copyMe);
        ~MyString();
        friend std::ostream& operator<<(std::ostream& out, const MyString& printMe);
        friend std::istream& operator>>(std::istream& in, MyString& readMe);
        void read(std::istream& in, char delimeter);
        static const int MAX_INPUT_SIZE = 127;
        char operator[] (int index) const;
        char& operator[](int index);
        friend bool operator<(const MyString& left, const MyString& right);
        friend bool operator>(const MyString& left, const MyString& right);
        friend bool operator<=(const MyString& left, const MyString& right);
        friend bool operator>=(const MyString& left, const MyString& right);
        friend bool operator==(const MyString& left, const MyString& right);
        friend bool operator!=(const MyString& left, const MyString& right);
        MyString operator=(const MyString& right);
        friend MyString operator+(const MyString& left, const MyString& right);
        MyString operator+=(const MyString& right);
        int length() const;
    private:
        char *str;
    };
}

#endif
