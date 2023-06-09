/*Date:8th June,2023
* Structured Bindings:  How to access individual members of tuples,pairs and structures with structured bindings. 
  And assign these values to individual variables.
  A lot of fundamental data structures from the STL are immediately accessible using structured bindings without us having to change anything.
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

