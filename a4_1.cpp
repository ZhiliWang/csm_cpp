/*------------------<CIS 278 Assignment 4>----------------
    * Student: Zhili Wang
    * Due Date: Sep 10th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 1
    * File Name: a4_1.cpp
    * Description: A program that takes an user input of 5
                   numbers as a hand of 5 poker cards and
                   determines what Hand Type it is, which
                   include high card, pair, two pairs,
                   three of a kind, straight, full house
                   and four of a kind.
---------------------------------------------------------*/

/*--------------------Global Variables---------------------
    @HAND_SIZE: size of the user input, which is consisting
                5 poker cards.
    @NUM: size of a frequency array to record number
          occurrences. It is 8 because there are 8 numbers
          in 2-9. Setting it exactly at 8 enables the
          program to end without telling the Hand Type when
          an user inputs a number out of the 2-9 range.
---------------------------------------------------------*/
#include <iostream>

using namespace std;

const int HAND_SIZE = 5;
const int NUM = 8;

void readCard(int hand[]);

bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);

/*-----------------------Functions------------------------
    main: creating an empty array that represents a hand
          of 5 cards and filling it with user input by
          calling the readCard function. With an array of
          5 cards, the later conditional statements will
          determine what Hand Type it is.

    @hand[HAND_SIZE]: an user input array that represents
                      a hand of 5 cards.
---------------------------------------------------------*/
int main() {
    int hand[HAND_SIZE];
    readCard(hand);

    if (containsFullHouse(hand))
        cout << "Full House!" << endl;
    else if (containsFourOfaKind(hand))
        cout << "Four of a Kind!" << endl;
    else if (containsThreeOfaKind(hand))
        cout << "Three of a Kind!" << endl;
    else if (containsTwoPair(hand))
        cout << "Two Pair!" << endl;
    else if (containsPair(hand))
        cout << "Pair!" << endl;
    else if (containsStraight(hand))
        cout << "Straight!" << endl;
    else
        cout << "High Card!" << endl;
}

/*-----------------------Functions------------------------
    readCard: asking an user to input 5 cards between 2-9,
              ignoring suits and face cards (A/J/Q/K).
---------------------------------------------------------*/
void readCard(int hand[]) {
    cout << "Enter five numeric cards, no face cards. Use 2-9." << endl;
    for (int i = 0; i < HAND_SIZE; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i];
    }
}

/*-----------------------Functions------------------------
    containsPair: checking if 2 of the 5 cards in the hand
                  are identical.
                  ***Important***
                  Unfortunately, without using any pointer,
                  I am not able to create a new helper
                  function that returns an array (for
                  Line 100-102). Therefore these 3 lines
                  will be repeatedly used in other Hand
                  Type functions.

    @countCard[NUM]: a frequency array that records the
                     number of occurrences among 2-9.
    @pair: checking the frequency array countCard to see
           if any number between 2-9 occurs twice.
---------------------------------------------------------*/
bool containsPair(const int hand[]) {
    int countCard[NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < HAND_SIZE; i++)
        countCard[hand[i] - 2] += 1;

    int pair = 0;
    for (int i = 0; i < NUM; i++) {
        if (countCard[i] == 2)
            pair += 1;
    }
    return pair == 1;
}

/*-----------------------Functions------------------------
    containsTwoPair: checking if there are 2 different
                     pairs in the 5 cards.

    @countCard[NUM]: a frequency array that records the
                     number of occurrences among 2-9.
    @pair: checking the frequency array countCard to see
           if any number between 2-9 occurs twice.
---------------------------------------------------------*/
bool containsTwoPair(const int hand[]) {
    int countCard[NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < HAND_SIZE; i++)
        countCard[hand[i] - 2] += 1;

    int pair = 0;
    for (int i = 0; i < NUM; i++) {
        if (countCard[i] == 2)
            pair += 1;
    }
    return pair == 2;
}

/*-----------------------Functions------------------------
    containsThreeOfaKind: checking if 3 of the 5 cards in
                          the hand are identical.

    @countCard[NUM]: a frequency array that records the
                     number of occurrences among 2-9.
---------------------------------------------------------*/
bool containsThreeOfaKind(const int hand[]) {
    int countCard[NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < HAND_SIZE; i++)
        countCard[hand[i] - 2] += 1;

    for (int i = 0; i < NUM; i++) {
        if (countCard[i] == 3)
            return true;
    }
    return false;
}

/*-----------------------Functions------------------------
    containsStraight: checking if the 5 cards are in a
                      consecutive order. In order to
                      ensure the 5 cards are consecutive,
                      we must ensure there are 5
                      consecutive positions of the
                      frequency array countCard have
                      values of only 1.

    @countCard[NUM]: a frequency array that records the
                     number of occurrences among 2-9.
    @count: a counter variable that counts the streak of
            the consecutive number occurrences, and it
            must be 4 (excluding the first number itself)
            to make the function returning "True".
---------------------------------------------------------*/
bool containsStraight(const int hand[]) {
    int countCard[NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < HAND_SIZE; i++)
        countCard[hand[i] - 2] += 1;

    int count = 0;
    for (int i = 0; i < NUM; i++) {
        if (countCard[i] == 1 && countCard[i + 1] == 1) {
            count += 1;
        }
        if (count == 4) {
            return true;
        }
    }
    return false;
}


/*-----------------------Functions------------------------
    containsFullHouse: checking if there are both a pair
                       and a three-of-a-kind, which is
                       when both containsPair and
                       containsThreeOfaKind return "True".

    @countCard[NUM]: a frequency array that records the
                     number of occurrences among 2-9.
    @pair: storing the result of containsPair
    @threeKind: storing the result of containsThreeOfaKind
---------------------------------------------------------*/
bool containsFullHouse(const int hand[]) {
    int countCard[NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < HAND_SIZE; i++)
        countCard[hand[i] - 2] += 1;

    bool pair = containsPair(hand);
    bool threeKind = containsThreeOfaKind(hand);
    return pair && threeKind;
}

/*-----------------------Functions------------------------
    containsFourOfaKind: checking if 4 of the 5 cards in
                         the hand are identical.

    @countCard[NUM]: a frequency array that records the
                     number of occurrences among 2-9.
---------------------------------------------------------*/
bool containsFourOfaKind(const int hand[]) {
    int countCard[NUM] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < HAND_SIZE; i++)
        countCard[hand[i] - 2] += 1;

    for (int i = 0; i < NUM; i++) {
        if (countCard[i] == 4)
            return true;
    }
    return false;
}

/*--------------------------Output------------------------
Enter five numeric cards, no face cards. Use 2-9.
Card 1: 2
Card 2: 5
Card 3: 3
Card 4: 8
Card 5: 7
High Card!

Enter five numeric cards, no face cards. Use 2-9.
Card 1: 2
Card 2: 5
Card 3: 3
Card 4: 5
Card 5: 7
Pair!

Enter five numeric cards, no face cards. Use 2-9.
Card 1: 2
Card 2: 5
Card 3: 3
Card 4: 5
Card 5: 3
Two Pair!

Enter five numeric cards, no face cards. Use 2-9.
Card 1: 5
Card 2: 5
Card 3: 3
Card 4: 5
Card 5: 7
Three of a Kind!

Enter five numeric cards, no face cards. Use 2-9.
Card 1: 3
Card 2: 5
Card 3: 6
Card 4: 4
Card 5: 7
Straight!

Enter five numeric cards, no face cards. Use 2-9.
Card 1: 5
Card 2: 7
Card 3: 5
Card 4: 7
Card 5: 7
Full House!

Enter five numeric cards, no face cards. Use 2-9.
Card 1: 2
Card 2: 5
Card 3: 5
Card 4: 5
Card 5: 5
Four of a Kind!

Process finished with exit code 0
---------------------------------------------------------*/