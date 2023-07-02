/*
   Date: 2nd July, 2023
   Incorrect use of Iterators and pointers can lead to buggy code.
   example trying to access a vector past its maximum size.

   The GNU STL implementation has a debug mode, and the GNU C++ compiler as well as the LLVM clang C++ compiler both
   support additional libraries that can be used to produce extra-sensitive and verbose binaries for us, which immediately blow up on a
   large variety of bugs. This is easy to use and super useful.

   The debug mode is activated with the -D_GLIBCXX_DEBUG option in command line.
   https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html

    
*/
/*
   Sanitizer usually consists of an additional compiler module and a runtime library. 
   When sanitizers are activated, the compiler will add additional information and code to the binary,
   which results from our program. At runtime, the sanitizer libraries that are then linked into the program binary can, for example,  
   replace the malloc and free functions in order to analyze how the program deals with the memory it acquires.
   Sanitizers can detect different kinds of bugs. Just to list a few valuable examples:
   Out-of-bounds: This triggers whenever we access an array, vector, or anything similar outside its legitimate memory range.
   Use-after-free: This triggers if we reference heap memory after it was already freed (which we did in this section).
   Integer overflow: This triggers if an integer variable overflows by calculating with values thatÂ do not fit into the variable. 
                     For signed integers, the arithmetic wraparound is undefined behavior.
   Pointer alignment: Some architectures cannot access memory if it has a weird alignment in memory
*/

#include<iostream>
#include<vector>

using namespace std;
int main()
{
   
   vector<int> v0={1,2,3};

   cout<<"Capacity: "<<v0.capacity()<<" ";

   vector<int>::iterator itr=v0.begin();

   cout<<"\n First number in vector: "<<*itr;
   v0.shrink_to_fit();

   cout<<"Capacity: "<<v0.capacity()<<" ";  
   v0.push_back(123);
  
/*now the iterator has become invalid, since all numbers have been pushed to a new and larger memory location.so old memory location has become invalid.*/

   cout<<"\n First number in vector: "<<*itr;//some random number is displayed,not correct.
  
       
}

