/*
   Date: 29th June, 2023
   C++17 STL , Jacek Golawckz, Packt Publishing
   Making our custom iterator compatible with STL algorithms.

   Motivation: Some STL algorithms do not compile with our custom iterators.
   The algorithms might be asking for more than we have provided in our custom interface.

   Test Results: The code compiled with and without iterator_traits. Added the --std=c++17 option on command line.
                 The results are largely compiler dependent.
   
   Notes:
   Automatic Optimization
   Different iterators might provide different possibilties to implement the same algorithm.
   
   For example, If we copy plain numbers from one std::vector to another, this may be implemented with a fast memcpy call. 
   If we copy data from or to std::list, this is not possible any longer and the items have to be copied individually one by one.
   Therefore, for automatic optimization by algorithms, we should equip our iterators with some information about themselves.

   iterator_traits<my_iterator> is used by the algorithm to get information about :
   1. Type/characteristics of iterator
   2. Type of data 

   This class iterator_traits contains 5 different type member definitions
   1-->difference_type:what type results from writting it1-it2?
   2-->value_type: what is the type of item obtained with *it?(dereferencing an iterator)
   3-->pointer: what should be the pointer type in order to point to an item?
   4-->reference: of what type must the reference be in order to reference an item?
   5-->iterator_category :which category does the iterator belong to?

   Until C++17, it was encouraged to let iterator types just inherit from std::iterator<...>, which automatically populates
   our class with all the type definitions. This still works, but it is discouraged since C++17.

  Types of iterators:
  Input iterators: Input iterators can be dereferenced only for reading the values they point to.
  Once they are incremented, the last value they pointed to has been invalidated during the incrementation.
  This means that it is not   possible to iterate over such a range multiple times. The std::istream_iterator is an
  example for this category.

  Forward iterator: Forward iterators are the same as input iterators, but they differ in that regard
  that the ranges they represent can be iterated over multiple times.The std::forward_list iterators are an example of that. 
  Such a list can only be iterated over forward, not backward, but it can be iterated over as often as we like to.

  The bidirectional iterator, as the name suggests, can be incremented and decremented, in order to iterate forward or backward. 
  The iterators of std::list, std::set, and std::map, for example, support that.

   Random access iterator allow jumping over multiple values at once, instead of single-stepping.
   This is the case for iterators of std::vector and std::deque.

   Contiguous iterator
   This category specifies all of the aforementioned requirements, plus the requirement that the data that is being
   iterated through lies in contiguous memory, like it does in an array, or std::vector.

   Output iterator
   Output iterators are detached from the other categories. This is because an iterator can be a pure output iterator, 
   which can only be incremented and used to write to the data it points to. If they are being read from, the value will be
   undefined.

   Mutable iterator: If an iterator is an output iterator and one of the other categories at the same
   time, it is a mutable iterator. It can be read from and written to. 
   If we obtain an iterator from a non-const container instance, it will usually be of this kind.
  
*/


#include<iostream>
#include<algorithm>

class num_iterator
{
  int i;
 public:
  explicit num_iterator(int position=0):i{position}{}
  num_iterator& operator++(){++i;return *this ;}
  int operator*()const {return i;}
  bool operator!=(const num_iterator& other)const{return i!=other.i;}
  bool operator==(const num_iterator& other)const{return i==other.i;}
};

/*We need to activate the iterator traits functionality for our num_iterator*/
namespace std{
  template <>
  struct iterator_traits<num_iterator>
  {
     using iterator_category= std::forward_iterator_tag;
     using value_type=int;
  };
}

class num_range
{
  int a;
  int b;
 public:
  explicit num_range(int from, int to ):a{from},b{to}{}
  num_iterator begin()const{return num_iterator(a);}
  num_iterator end()const {return num_iterator(b);}
};

using namespace std;
int main()
{
   num_range r{90,100};

   /*And now, we use it with std::minmax_element. 
     This algorithm returns us std::pair with two members: an iterator pointing to the
     lowest value and another iterator pointing to the highest value in the range. 
     These are, of course, 90 and 100 because that's how we constructed the range:*/

     auto [min_it, max_it] (minmax_element(begin(r), end(r)));//lambda here
     cout << *min_it << " - " << *max_it << '\n';
}