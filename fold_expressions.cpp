/*
* Date: 10th June,2024
* fold expressions are a substitute for variadac templates. Left and Right associative folds.
* reference:https://www.geeksforgeeks.org/features-of-c17-with-examples/
*/

/*
   // Below is the function that implements folding expressions using variable number of arguments
 
int sum(int num, ...)
{
    va_list valist;
 
    int s = 0, i;
 
    va_start(valist, num);
    for (i = 0; i < num; i++)
        s += va_arg(valist, int);
 
    va_end(valist);
 
    return s;
}
*/

/*

where pack represents an unexpanded parameter pack, op represents an operator and init represents a value. 

* (pack op …): This is a right fold that is expanded like pack1 op (… op (packN-1 op packN)).
* (… op pack): This is a left fold that is expanded like ((pack1 op pack2) op …) op packN.
* (pack op … op init): This is a binary right fold that is expanded like pack1 op (… op (packN-1 op (packN op init))).
* (init op … op pack): This is a binary left fold that is expanded like (((init op pack1) op pack2) op …) op packN.

*/

// C++ program to illustrate the folding expression in C++17
 
#include <iostream>
#include <string>
using namespace std;
 
// Template Class
template<typename... Args>
auto sum(Args... args)
{
    return (args + ... + 0);
}
 
template <typename... Args>
auto sum2(Args... args)
{
    return (args + ...);
}
 
// Driver Code
int main()
{
    // Function Calls
    cout << sum(11, 22, 33, 44, 55)
         << "\n";
     
    cout << sum2(11, 22, 33, 44, 55)
         << "\n";
 
    return 0;
}