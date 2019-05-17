/*------------------<CIS 278 Assignment 12>------------------
    * Student: Zhili Wang
    * Due Date: Nov 14th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: mystring.cpp
    * The implementation file of mystring class
-----------------------------------------------------------*/

#include <iostream>
#include <cassert>
#include "mystring.h"

using namespace std;






namespace cs_mystring {

    MyString::MyString(){
        description = new char[1];
        strcpy(description, "");
    }






    MyString::MyString(const char* inDesc) {
        description = new char[static_cast<int> (strlen(inDesc)) + 1];
        strcpy(description, inDesc);
    }






    MyString::MyString(const MyString& right) {
        description = new char[right.length() + 1];
        strcpy(description, right.description);
    }









    MyString::~MyString() {
        delete [] description;
    }






    MyString& MyString::operator = (const MyString& right) {
        if (this != &right){
            delete [] description;
            description = new char[right.length() + 1];
            strcpy(description, right.description);
        }
        return *this;
    }






    char MyString::operator [] (int index) const {
        assert(index >= 0 && index < length());
        return description[index];
    }






    char& MyString::operator[] (int index) {
        assert(index >= 0 && index < length());
        return description[index];
    }






    int MyString::length() const {
       return static_cast<int> (strlen(description));
    }






    ostream &operator << (std::ostream &out, const MyString &source) {
        out << source.description;
        return out;
    }






    bool operator < (const MyString &left, const MyString &right) {
        return (strcmp(left.description, right.description) < 0);
    }






    bool operator <= (const MyString &left, const MyString &right) {
       return (strcmp(left.description, right.description) <= 0);
    }






    bool operator > (const MyString &left, const MyString &right) {
        return (strcmp(left.description, right.description) > 0);
    }






    bool operator >= (const MyString &left, const MyString &right){
        return (strcmp(left.description, right.description) >= 0);
    }






    bool operator == (const MyString &left, const MyString &right) {
        return (strcmp(left.description, right.description) == 0);
    }






    bool operator != (const MyString &left, const MyString &right) {
        return (strcmp(left.description, right.description) != 0);
    }
}