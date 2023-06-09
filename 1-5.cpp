/*
* Date: 8 June,2023
* Reference: Jacek Golawicz, c++17 STL cookbook, Packt Publishing
*C++17,It is good style to limit the scope of variables as much as possible.Before C++17, this was only possible using extra braces around
the code, as the pre-C++17 examples show. The short lifetimes reduce the number of variables in the scope, which keeps our code tidy and makes it
easier to refactor */

/*
  Before C++17:
  {
    auto var (init_value);
    if (condition) 
    {
      // branch A. var is accessible
    
    }
    else   
    {
      // branch B. var is accessible
    }
    // var is still accessible
   }
   after c++17
   if (auto var (init_value); condition)//variable is declared within the if statement 
   {
      // branch A. var is accessible
   } 
   else 
   {
       // branch B. var is accessible
   } 
    // var is not accessible any longer
*/

/*
   Before C++17:
  {
    auto var (init_value);
    switch (var) {
    case 1: ...
    case 2: ...
    ...
     }
   }
   Since C++17:
   switch (auto var (init_value); var) 
   {
     case 1: ...
     case 2: ...
     ...
   } // var is not accessible any longer
*/

#include<iostream>
#include<cstdlib>
#include<time.h>

int main(int i,char* args[])
{
    // Seed a rand function to be used later in program
    srand(time(NULL));

     if (int i = 4; i % 2 == 0  )
    std::cout << i << " is even number" << std::endl;
  
  // Switch statement
  // switch(init;variable)
  switch (int i = rand() % 100; i) {
      default: 
         std::cout << "i = " << i << std::endl; break;
  }  
}