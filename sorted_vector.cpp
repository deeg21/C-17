/*
   Date: 27th June,2023
   Sorting a vector as items are added.
   we will fill an std::vector with random words, sort it, and then insert more words while keeping the vector's sorted word order intact.
   Reference: Jacek Galowickz, C++17 STL

   status: tested, Need to study more on lower bound(), and insert())
            This example shows that random insertion at a particular index is possible in vectors. 
            whereas a vector only supports push_back, functions and random access.
   
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

/*
  For any new string, it locates the position in the sorted vector, at which it must be inserted, in order to preserve the order
of the strings in the vector. However, we assume that the vector was sorted before. Otherwise, this would not work.

The locating step is done by the STL function lower_bound, which accepts three arguments. The first two denote beginning and end of the underlying range. The range is our vector of words in this case. The third argument is the word, which shall be inserted. The function then finds the first item in the range, which is greater than or equal to that third parameter and returns an iterator pointing to it.

*/

void insert_sorted(vector<string> &v, const string &word)
{
   const auto insert_pos (lower_bound(begin(v), end(v), word));
   v.insert(insert_pos, word);
}

int main()
{
   vector<string> v {"some", "random", "words", "without", "order", "aaa","yyy"};
   
   assert(false == is_sorted(begin(v), end(v)));
   sort(begin(v), end(v));
   assert(true == is_sorted(begin(v), end(v)));

   insert_sorted(v, "foobar");
   insert_sorted(v, "zzz");
   
   for (const auto &w : v) 
   {
     cout << w << " ";
   }
   cout << '\n';
}