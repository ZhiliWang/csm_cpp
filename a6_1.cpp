/*------------------<CIS 278 Assignment 6>----------------
    * File Name: a6_1.cpp
    * Author: Zhili Wang
    * Due Date: Sep 24th 2018
    * Instructor: Dave Harden
    * Course: CIS 278
    * Number of Problem(s): 2
    * Description: A sequence of tasks that Focuses on
                   Pointers and Dynamic Memory
---------------------------------------------------------*/
#include <iostream>

using namespace std;

void noNegatives(int *x);

void swap(int *a, int *b);






/*-----------------------Functions------------------------
    main: Executing a sequence of tasks except Task 11
          (noNegatives method) and Task 21 (swap method)
---------------------------------------------------------*/
int main() {
    // 1. Create two integer variables named x and y
    int x, y;

    // 2. Create an int pointer named p1
    int *p1 = nullptr;

    // 3. Store the address of x in p1
    p1 = &x;

    // 4. Use only p1 (not x) to set the value of x to 99
    *p1 = 99;

    // 5. Using cout and x (not p1), display the value of x
    cout << "Displaying x using cout and x (not p1): " << x << endl;

    // 6. Using cout and the pointer p1 (not x), display the value of x
    cout << "Displaying x using cout and the pointer p1: " << *p1 << endl;

    // 7. Store the address of y into p1
    p1 = &y;

    // 8. Use only p1 (not y) to set the value of y to -300
    *p1 = -300;

    /* 9. Create two new variables: an int named temp, and an int pointer named p2.
         Make p2 point to x. */
    int temp;
    int* p2 = nullptr;
    p2 = &x;

    /* 10. Use only temp, p1, and p2 (not x or y) to swap the values in x and y
       (this will take a few statements. Don't use a swap function) */
    cout << "\nBefore swapping, the value of x is " << x
         << " and the value of y is " << y
         << "." << endl;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << "After swapping, the value of x is " << x
         << " and the value of y is " << y
         << ".\n" << endl;

    /* 12. Invoke the function twice: once with the address of x as the argument,
       and once with the address of y. Use x or y for the argument (not p1 or p2) */
    noNegatives(&x);
    noNegatives(&y);

    /* 13. Use p2 to display the values in x and y (this will require both assignment
       statements and cout statements).
       You can use x and y in assignment statements, but not in your cout statement.
       This should produce the output:
       x is: 0
       y is: 99 */
    *p2 = 0;
    cout << "x is: " << *p2 << endl;
    p2 = &y;
    *p2 = 99;
    cout << "y is: " << *p2 << endl;

    /* 14. Create an int array named 'a' with two elements.
       Make p2 point to the first element of a. */
    int* a = new int[2];
    a[0] = *p2;

    // 15. Use only p2 and x (not a) to initialize the first element of a with the value of x.
    *p2 = x;

    /* 16. Use only p2 and y (not a) to initialize the second element of a with the value of y.
       Leave p2 pointing to the first element of a. Don't use pointer arithmetic.
       Hint: don't forget that pointers and arrays are the same thing. */
    a[1] = *p2;
    *(p2 + 1) = y;

    // 17. Using cout and p2 only, display the address of the first element in a.
    cout << "\nThe address of the first element in a is: " << &p2[0] << endl;

    /* 18. Using cout and p2 only, display the address of the second element in a.
       Leave p2 pointing to the first element of a. Don't use pointer arithmetic. */
    cout << "The address of the second element in a is: " << &p2[1] << endl;

    /* 19. Use p1, p2, and temp to swap the values in the two elements of array 'a'.
       (first point p1 at a[0], then point p2 at a[1], then do not use "a" again.
       After this the swapping steps should look very similar to step 10. Don't use a swap function.) */
    p1 = &a[0];
    p2 = &a[1];
    cout << "\nBefore swapping, the first element of \"a\" is " << *p1
         << " and the second value of \"a\" is " << *p2
         << "." << endl;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // 20. Display the values of the two elements. (The first element should be 99, the second 0).
    cout << "\nAfter swapping, the first element of \"a\" is " << *p1
         << " and the second value of \"a\" is " << *p2
         << "." << endl;

    /* 22. Invoke your swap function with the addresses of x and y (using the address-of operator),
       then print their values. (x should be 99, y should be 0). */
    swap(&x, &y);
    cout << "\nAfter invoking the swap function with the addresses of x and y,"
         << " the value of x is " << a[0]
         << " and the value of y is " << a[1]
         << "." << endl;

    /* 23. Invoke your swap function with the address of the two elements in array 'a', then print
       their values. (a[0] should be 0, a[1] should be 99) */
    swap(&a[0], &a[1]);
    cout << "\nAfter invoking the swap function with the addresses of the 2 elements in \'a\'"
         << " the value of x is " << a[0]
         << " and the value of y is " << a[1]
         << "." << endl;
}






    /* 11. Write a function with the following signature: void noNegatives(int *x).
     * The function should accept the address of an int variable.
     * If the value of this integer is negative then it should set it to zero */
void noNegatives(int *x){
    if (*x < 0) {
        *x = 0;
    }
}






    /* 21. Write a function named 'swap' that accepts two pointers to integers as arguments,
       and then swaps the contents of the two integers. Do not use any reference parameters. */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*--------------------------Output------------------------
Displaying x using cout and x (not p1): 99
Displaying x using cout and the pointer p1: 99

Before swapping, the value of x is 99 and the value of y is -300.
After swapping, the value of x is -300 and the value of y is 99.

x is: 0
y is: 99

The address of the first element in a is: 0x7ffee67eda78
The address of the second element in a is: 0x7ffee67eda7c

Before swapping, the first element of "a" is 99 and the second value of "a" is 0.

After swapping, the first element of "a" is 0 and the second value of "a" is 99.

After invoking the swap function with the addresses of x and y, the value of x is 0 and the value of y is 99.

After invoking the swap function with the addresses of the 2 elements in 'a' the value of x is 99 and the value of y is 0.

Process finished with exit code 0

---------------------------------------------------------*/

