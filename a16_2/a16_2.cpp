/*------------------<CIS 278 Assignment 7>----------------
    * File Name: a16_2.cpp
    * Author: Zhili Wang
    * Due Date: Dec 5th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 3
    * Description: 
---------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iomanip>
#include "mystring.h"

using namespace cs_mystring;
using namespace std;



bool isAPalindrome(const MyString inString, int startingCharIndex, int endingCharIndex);

int main() {
    MyString str;
    while (str != "quit"){
        cout << "Enter a string: ";
        str.read(cin, '\n');
        if (str != "quit"){
            if (isAPalindrome(str, 0, str.length() - 1)){
                cout << str << " is a palindrome." << endl;
            } else {
                cout << str << " is not a palindrome." << endl;
            }
        }
    }
}



/**
 Function Definition of isAPalindrome:
 This recursive function determines if a word or phrase is a palindrome and gives
 no special treatement to characters that are not alphabetical.  Returns a
 boolean value.
 pre:  A constant character array as input
 post:  Returns true if it is a palindrom.  Returns false if it
        is not a palindrome.
 **/



// pre:  A constant string as input declared from MyString class
// post:  Returns true if it is a palindrome.  Returns false if it
// is not a palindrome.


/*******************************************************************************
 Function Definition of isAPalindrome:
 This recursive function determines if a word or phrase is a palindrome.  It
 ignores characters that are either a space or punctuation.  It is not
 case sensitive and and returns a boolean value.
 *******************************************************************************/


bool isAPalindrome(const MyString inString, int startingCharIndex, int endingCharIndex){
    bool isPalindrome = true;
    char startingCharacter = toupper(inString[startingCharIndex]);
    char endingCharacter = toupper(inString[endingCharIndex]);
    if (isspace(startingCharacter) || ispunct(startingCharacter)){
        startingCharIndex++;
    }
    if (isspace(endingCharacter) || ispunct(endingCharacter)){
        endingCharIndex--;
    }
    if (!isspace(startingCharacter) && !ispunct(startingCharacter)
        && !isspace(endingCharacter) && !ispunct(endingCharacter)){
        if (startingCharacter != endingCharacter){
            isPalindrome = false;
            return isPalindrome;
        }
        startingCharIndex++;
        endingCharIndex--;
    }
    if (startingCharIndex < endingCharIndex){
        isPalindrome = isAPalindrome(inString, startingCharIndex, endingCharIndex);
    }
    return isPalindrome;
}

