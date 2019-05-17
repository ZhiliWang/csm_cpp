/*------------------<CIS 278 Assignment 7>----------------
    * File Name: a7_1.cpp
    * Author: Zhili Wang
    * Due Date: Oct 1st 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * Description: Implement a sequence of functions that
                 deal with null terminated C-Style strings
---------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE = 1000;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);






/*-----------------------Functions------------------------
    main: Implementing a sequence of functions that
          deal with null terminated C-Style strings
---------------------------------------------------------*/
int main() {

    cout << "-----------Testing lastIndexOf()-----------" << endl;
    char input1[] = "programming";
    char char1 = 'a';
    char input2[] = "homework";
    char char2 = 'k';

    cout << "Case 1: Let's test: " <<  input1 << endl;
    cout << "The last index where \"" << char1 << "\" is present is at index "
         << lastIndexOf(input1, char1) << endl;

    cout << "\nCase 2: Let's test: " <<  input2 << endl;
    cout << "The last index where \"" << char2 << "\" is present is at index "
         << lastIndexOf(input2, char2) << endl;

    cout << "\n-----------Testing Function reverse-----------" << endl;
    char rev_input1[] = "abcde";
    char rev_input2[] = "Hello World!";

    cout << "Case 1: We are reversing the following term: " << rev_input1 << endl;
    reverse(rev_input1);
    cout <<  "The result is: " << rev_input1 << endl;

    cout << "\nCase 2: Let's also try the classic \"" << rev_input2 << "\"" << endl;
    reverse(rev_input2);
    cout << "After reversing we have: " << rev_input2 << endl;

    cout << "\n-----------Testing Function replace-----------" << endl;
    char rep_input1[SIZE] = "college";
    char replace1 = 'e';
    char replacement1 = 'i';

    char rep_input2[SIZE] = "surfing";
    char replace2 = 'u';
    char replacement2 = 'e';

    cout << "Case 1: If we replace \"" << replace1 << "\" in " << rep_input1
         << ", it will be replaced " << replace(rep_input1, replace1, replacement1)
         << " times." << endl << endl;

    cout << "Case 2: If we replace \"" << replace2 << "\" in " << rep_input2
         << ", it will be replaced " << replace(rep_input2, replace2, replacement2)
         << " times." << endl;


    cout << "\n-----------Testing Function isPalindrome-----------" << endl;
    char pau_input1[SIZE] = "Madam";
    char pau_input2[SIZE] = "Adam";

    if(isPalindrome(pau_input1)) {
        cout << "Case 1: The word " << pau_input1 << " is a Palindrome." << endl << endl;
    } else {
        cout << "Case 1: The word " << pau_input1 << " is not a Palindrome." << endl << endl;
    }

    if(isPalindrome(pau_input2)) {
        cout << "Case 2: The word " << pau_input2 << " is a Palindrome." << endl;
    } else {
        cout << "Case 2: The word " << pau_input2 << " is not a Palindrome." << endl;
    }

    cout << "\n-----------Testing Function toupper-----------" << endl;
    char upper_input1[SIZE] = "Listen to me!";
    char upper_input2[SIZE] = "Are you serious?";

    cout << "Case 1: " << upper_input1 << " Now I will repeat this but louder (applying toupper): " << endl;
    toupper(upper_input1);
    cout << upper_input1 << endl << endl;

    cout << "Case 2: " << upper_input2 << " I meant (applying toupper): " << endl;
    toupper(upper_input2);
    cout << upper_input2 << endl;

    cout << "\n-----------Testing Function numLetters-----------" << endl;
    char count_input1[SIZE] = "word";
    char count_input2[SIZE] = "I love you!";

    cout << "Case 1: The word \"" << count_input1 << "\" consists of "
         << numLetters(count_input1) << " letters." << endl << endl;

    cout << "Case 2: There is something I want you to know, 3 words with "
         << numLetters(count_input2) << " letters: "
         << count_input2 << endl;

}






/* This function finds the last index where the target char can be found in the string.
 * It returns -1 if the target char does not appear in the string.
 * The function should be case sensitive (so 'b' is not a match for 'B'). */

int lastIndexOf(const char* inString, char target) {
    int index = 0;
    int lastIndex = -1;

    while(*inString != '\0') {
        if(target == *inString) {
            lastIndex = index;
        }
        inString++;
        index++;
    }
    index = lastIndex;

    return index;
}






/* This function alters any string that is passed in. It should reverse the string.
 * If "flower" gets passed in it should be reversed in place to "rewolf".
 * For efficiency, this must be done "in place", i.e., without creating a second array. */

void reverse(char* inString) {
    int index = 0;
    int length = strlen(inString);

    char temp;

    for (index = 0; index < length / 2; index++) {
        int end = length - index -1;
        temp = inString[index];
        inString[index] = inString[end];
        inString[end] = temp;
    }
}






/* This function finds all instances of the char 'target' in the string and replace them with 'replacementChar'.
 * It returns the number of replacements that it makes.
 * If the target char does not appear in the string it should return 0. */

int replace(char* inString, char target, char replacementChar) {
    int counter = 0;

    while(*inString != '\0') {
        if(*inString == target) {
            *inString = replacementChar;
            counter++;
        }
        inString++;
    }

    return counter;
}






/* This function returns true if the argument string is a palindrome.
 * It returns false if it is no. A palindrome is a string that is spelled the same as its reverse.
 * For example "abba" is a palindrome. So are "hannah" and "abc cba".
 * Do not get confused by white space characters, punctuation, or digits.
 * They should not get any special treatment. "abc ba" is not a palindrome.
 * It is not identical to its reverse.
 * Your function should not be case sensitive. For example, "aBbA" is a palindrome.
 * You must solve this problem "in place", i.e., without creating a second array.
 * As a result, calling your reverse() function from this function isn't going to help. */

bool isPalindrome(const char* inString) {
    int index = 0;
    int length = strlen(inString);
    int end = length - index - 1;
    int mid = (index + end) / 2;

    int firstChar = tolower(inString[index]);
    int endChar = tolower(inString[end]);

    while (firstChar == endChar && index < mid) {
        index++;
    }

    return index == mid;
}






// This function converts the c-string parameter to all uppercase.

void toupper(char* inString) {
    while (*inString != '\0'){
        *inString = toupper(*inString);
        inString++;
    }
}






// This function returns the number of letters in the c-string.

int numLetters(const char* inString) {
    int counter = 0;
    while (*inString != '\0') {
        if (isalpha(*inString)) {
            counter++;
        }
        inString++;
    }

    return counter;
}

/*--------------------------Output------------------------
-----------Testing lastIndexOf()-----------
Case 1: Let's test: programming
The last index where "a" is present is at index 5

Case 2: Let's test: homework
The last index where "k" is present is at index 7

-----------Testing Function reverse-----------
Case 1: We are reversing the following term: abcde
The result is: edcba

Case 2: Let's also try the classic "Hello World!"
After reversing we have: !dlroW olleH

-----------Testing Function replace-----------
Case 1: If we replace "e" in college, it will be replaced 2 times.

Case 2: If we replace "u" in surfing, it will be replaced 1 times.

-----------Testing Function isPalindrome-----------
Case 1: The word Madam is a Palindrome.

Case 2: The word Adam is not a Palindrome.

-----------Testing Function toupper-----------
Case 1: Listen to me! Now I will repeat this but louder (applying toupper):
LISTEN TO ME!

Case 2: Are you serious? I meant (applying toupper):
ARE YOU SERIOUS?

-----------Testing Function numLetters-----------
Case 1: The word "word" consists of 4 letters.

Case 2: There is something I want you to know, 3 words with 8 letters: I love you!

Process finished with exit code 0
---------------------------------------------------------*/