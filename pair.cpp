/*
* Date 13th June,2023
* https://en.cppreference.com/w/cpp/utility/pair
* std::pair is a class template that provides a way to store two heterogeneous objects as a single unit. 
* A pair is a specific case of a std::tuple with two elements.
* The pair container is a simple container defined in <utility> header.
* 1. The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
  2.Pair can be assigned, copied, and compared. The array of objects allocated in a map or hash_map is of type ‘pair’ 
    by default in which  all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
  3.To access the elements, we use variable name followed by dot operator followed by the keyword first or second.
* std::get,make_pair, std::tuple_size, std::tuple_element(type of elements of the pair),std::swap(),

  *****Pair Initialisation*************************
   pair (data_type1, data_type2) Pair_name (value1, value2) ;
   Different ways to initialize pair:  

   pair  g1;         //default
   pair  g2(1, 'a');  //initialized,  different data type
   pair  g3(1, 10);   //initialized,  same data type
   pair  g4(g3);    //copy of g3
   Another way to initialize a pair is by using the make_pair() function. 
   g2 = make_pair(1, 'a');
   
   Another valid syntax to declare pair is
   g2 = {1, 'a'};
*/


#include <utility>
#include<iostream>
#include<string>

//using namespace std;
  
// Driver Code
int main()
{
    // defining a pair
    std::pair<int, char> pair1;
    std::pair<char,std::string> pair2('A',"Johnson");
    std::pair<std::string,int> pair3={"Barbara",0};
    std::pair<std::string,int> pair4(pair3);

  

    // first part of the pair

    pair1.first = 100;
    // second part of the pair
    pair1.second = 'G';
  
    std::cout << pair1.first << " ";
    std::cout << pair1.second << "\n";
  
    std::cout<<" Pair2: "
             << pair2.first << " "
             << pair2.second << "\n";

    std::cout<<" Pair3: "
             << pair3.first << " "
            << pair3.second << "\n";

    std::cout<<" Pair4: "
             << pair4.first << " "
             << pair4.second << "\n";

    pair4.first="Babua";
    pair4.second=223;
    std::swap(pair4,pair3);
    std::cout<<"Pair3 after swapping: "
             << pair3.first << " "
             << pair3.second << "\n";
    
     std::cout<<"Pair4 after swapping: "
              << pair4.first << " "
             << pair4.second << "\n";
    
    return 0;
}