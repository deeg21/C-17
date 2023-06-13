/*Date:8th June,2023
* Structured Bindings:  How to access individual members of tuples,pairs, structures,static arrays with structured bindings. 
  And assign these values to individual variables.
  A lot of fundamental data structures from the STL are immediately accessible using structured bindings without us having to change
  anything.
 The list of variablesÂ var1, var2, ... must exactly match the number of variables contained by the expression being assigned from.
 The <pair, tuple, struct, or array expression> must be one of the following:
   An std::pair.
   An std::tuple.
   A struct. 
  All members must be non-static and defined in the same base class. The first declared member is assigned to the first
  variable, the second member to the second variable, and so on.

  **------An array of fixed size. The type can be auto, const auto, const auto&, and even auto&&.------****
* Reference: Jaceq Golakwiz, c++17 STL Cookbook, Packt Publishing.
* status : compiled on g++, and results verified.  
*/

#include<iostream>
#include<vector>
#include<map>


/*** Returning multiple values from a function:-https://cplusplus.com/forum/beginner/272033/*****/
std::tuple<int, double, std::string> returnTuple()
{
    return { 5, 6.7 , "Hello Sailor"};
}

int main(int n,char* args[])
{
   
   /*****Tuples******/
  
   auto [a, b, c]{ returnTuple() };
   std::cout << a << ' ' << b << ' ' << c << '\n';

   /***structures****/
   struct employee
   {
     unsigned id;
     std::string name;
     std::string role;
     unsigned salary;
   };
   std::vector<employee> emp;
   //initialise the vector
   for(const auto &[id, name, role, salary] : emp)
   std::cout<<"Name: "<<name<<"Role: "<<role<<"Salary: "<<salary<<"\n";
   
   std::map<std::string, size_t> animal_population
   {
     {"humans", 7000000000},
     {"chickens", 17863376000},
     {"camels", 24246291},
     {"sheep", 1086881528},
      
   };
   for (const auto &[species, count] : animal_population)
   {
     std::cout << "There are " << count << " " << species<< " on this planet.\n";
   }
  
   
}

