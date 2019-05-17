/*------------------<CIS 278 Assignment 8>----------------
    * Student: Zhili Wang
    * Due Date: Oct 8th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: a8_1.cpp
    * Description: A program that records high-score data
      for a fictitious game. The program will ask the user
      to enter five names, and five scores. It will store
      the data in memory, and print it back out sorted by
      score.
---------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;

const int CHAR_SIZE = 24;

struct highscore {
    int score;
    char name[CHAR_SIZE];
};

void initializeArrays(highscore scores[], int size);
void sortData(highscore scores[], int size);
void displayData(const highscore scores[], int size);
void swap(highscore &a, highscore &b);






/*-----------------------Functions------------------------
    main: initializing a highscore pointer with size, and
          run the 3 functions of this program (excluding
          one helper function)

    @size: number of participants that users can input
    @hsPtr: a highscore pointer
---------------------------------------------------------*/
int main() {
    int size;
    cout << "How many players do we have? ";
    cin >> size;
    cin.ignore();

    highscore* hsPtr = nullptr;
    hsPtr = new highscore[size];

    initializeArrays(hsPtr, size);
    sortData(hsPtr, size);
    displayData(hsPtr, size);
    delete [] hsPtr;
}






/*-----------------------Functions------------------------
    initializeArrays: initializing the names and scores
                      arrays while creating a couple user
                      inputs for them
---------------------------------------------------------*/
void initializeArrays(highscore scoreList[], int size) {

    for (int i = 0; i < size; i++) {
        cout << "Enter the name for Player #" << i + 1 << ": ";
        cin.getline(scoreList[i].name, CHAR_SIZE);
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scoreList[i].score;
        cin.ignore();
    }
}






/*-----------------------Functions------------------------
    sortData: sorting both names and scores arrays with
              a selection sort algorithm. It has a
              relatively lower time complexity

    @minIndex: the index of the minimum value
    @minValue: temporarily stores the minimum scores while
               sorting
    @minName: temporarily stores the player name with the
              minimum score
---------------------------------------------------------*/
void sortData(highscore scoreList[], int size) {
    int minIndex, minValue;
    string minName;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = scoreList[start].score;

        for (int index = start + 1; index < size; index++) {
            if (scoreList[index].score > minValue) {
                minValue = scoreList[index].score;
                minIndex = index;
            }
        }

        swap(scoreList[minIndex], scoreList[start]);
    }
}






/*-----------------------Functions------------------------
    displayData: printing and displaying the sorted array
---------------------------------------------------------*/
void displayData(const highscore scoreList[], int size) {
    cout << "\nTop Scorers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << scoreList[i].name << ": "
             << scoreList[i].score << endl;
    }
}






/*-----------------------Functions------------------------
    swap: with two input integers, this function swaps
          their positions

    @a: the first swapped integer
    @b: the second swapped integer
    @temp: temporarily stores the value of a to make the
           swap easier
---------------------------------------------------------*/
void swap(highscore &a, highscore &b) {
    highscore temp = a;
    a = b;
    b = temp;
}






/*--------------------------Output------------------------
How many players do we have? 3
Enter the name for Player #1: Zenith
Enter the score for score #1: 12321
Enter the name for Player #2: Cameron
Enter the score for score #2: 99999
Enter the name for Player #3: Jonny
Enter the score for score #3: 32123

Top Scorers:
Cameron: 99999
Jonny: 32123
Zenith: 12321

Process finished with exit code 0
---------------------------------------------------------*/



