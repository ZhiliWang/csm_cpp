/*------------------<CIS 278 Assignment 5>----------------
    * Student: Zhili Wang
    * Due Date: Sep 17th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: a5_1.cpp
    * Description: A program that records high-score data
      for a fictitious game. The program will ask the user
      to enter five names, and five scores. It will store
      the data in memory, and print it back out sorted by
      score.
---------------------------------------------------------*/
#include <iostream>

using namespace std;

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);
void swap(int &a, int &b);







/*-----------------------Functions------------------------
    main: initializing 2 arrays with sizes of 5, and run
          the 3 functions of this program (excluding one
          helper function)

    @size: for this program we set input and output sizes
           at 5 (5 records).
    @scores[size]: an array consisting 5 player scores.
    @names[size]: an array consisting 5 player names.
---------------------------------------------------------*/
int main() {
    const int size = 5;
    int scores[size];
    string names[size];
    initializeArrays(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);
}






/*-----------------------Functions------------------------
    initializeArrays: initializing the names and scores
                      arrays while creating a couple user
                      inputs for them
---------------------------------------------------------*/
void initializeArrays(string names[], int scores[], int size) {
    names[size];
    scores[size];
    for (int i = 0; i <  size; i++) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i];
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
void sortData(string names[], int scores[], int size) {
    int minIndex, minValue;
    string minName;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = scores[start];
        minName = names[start];
        for (int index = start + 1; index < size; index++) {
            if (scores[index] > minValue) {
                minValue = scores[index];
                minName = names[index];
                minIndex = index;
            }
        }
        swap(scores[minIndex], scores[start]);
        swap(names[minIndex], names[start]);
    }
}






/*-----------------------Functions------------------------
    displayData: printing and displaying the sorted array
---------------------------------------------------------*/
void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop Scorers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << names[i] << ": " << scores[i] << endl;
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
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}






/*--------------------------Output------------------------
Enter the name for score #1: Zach
Enter the score for score #1: 32768
Enter the name for score #2: April
Enter the score for score #2: 256
Enter the name for score #3: Donald
Enter the score for score #3: 16384
Enter the name for score #4: Bobby
Enter the score for score #4: 2048
Enter the name for score #5: Corey
Enter the score for score #5: 4096

Top Scorers:
Zach: 32768
Donald: 16384
Corey: 4096
Bobby: 2048
April: 256

Process finished with exit code 0
---------------------------------------------------------*/



