/*
   Date: 27th June,2023
   insert() function in vector

  Causes reallocation if the new size() is greater than the old capacity(). 
  If the new size() is greater than capacity(), all iterators and references are invalidated. 
  Otherwise, only the iterators and references before the insertion point remain valid. The end() iterator is also invalidated.

   This is generally an inefficient operation as all elements after insert position are reallocated to new position.
   insert is more efficient in list, forward_list.
*/


#include<iostream>
#include<vector>
#include<iterator>	

using namespace std;

template<typename T>
void print(int id, const std::vector<T>& vec)
{
    std::cout << id << ". ";
    for (const T i: vec)
        std::cout << i << ' ';
    std::cout << '\n';
}
int main()
{
   vector<int> vec0(3,0);//create a vector with 3 values initialised to zero
   print(1,vec0);

   
   auto itr=vec0.insert(vec0.end(),300);//itr points to the inserted value
   print(2, vec0);

   itr=vec0.insert(itr, 2,100);
   print(3,vec0);

   itr=vec0.insert(vec0.begin(),2,400);
   print(4,vec0);

   vec0.insert(itr,500);
   print(5,vec0);
    
   vec0.insert(vec0.end(),{900,800,700});
   print(6,vec0);
   
    int arr[]={501,502,503};
    vec0.insert(vec0.end(),arr,arr+size(arr));
    print(7,vec0);
}
