/*
 *  Date:20 June,2023
 *  Reference: C++17 STL, Jack Golwickz
 *  when data is randomly removed from a vector, the vector does not shrink in size, so this needs to be taken care of manually.
 *  Status: Tested
*/

#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::vector <int> vec0{1,2,2,3,4,5,2,7,3,2,8,2,9};
    auto itr_end=std::remove(begin(vec0),end(vec0),2);
   
    std::cout<<"The vector";
    for(auto i:vec0) std::cout<<i<<",";
      std::cout<<"\n";
    
    std::cout<<"after removing all 2's";
    for(auto i:vec0) std::cout<<i<<",";
      std::cout<<"\n"<<"\n";
     vec0.erase(itr_end,end(vec0));//remove all elements from the new end of the vector to the end vector.

     std::cout<<"After erasing the vectors extra memory!!";
    for(auto i:vec0)  std::cout<<i<<",";
      std::cout<<"\n";

    std::cout<<"\n/**********************Lambda,Remove the odd values, Erase extra memory from vector*******************/\n";

    std::vector <int> vec1{107,30,31,47,52,23,76,39,25,84,29,98};

    const auto odd ([](int i) { return i % 2 != 0; });
    vec1.erase(std::remove_if(std::begin(vec1), std::end(vec1), odd), std::end(vec1));

    std::cout<<"After erasing the vectors extra memory!!";
    for(auto i:vec1)  std::cout<<i<<",";
      std::cout<<"\n";

  /* All odd items are gone now, but the vector's capacity is still at the original size. In a last step, we reduce that also to the actual current size of the vector. Note that this might lead the vector code to allocate a new chunk of memory that fits and moves all items from the old chunk to the new one.*/

   vec1.shrink_to_fit();
    
    

         

   

   
}