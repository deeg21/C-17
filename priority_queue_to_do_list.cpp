/*
   Date: 9th July, 2023
   Implementing a TODO list using priority queue and arrange the items according to highest to lowest priority.
   priority queue: a priority queue is another container adapter like std:stack.
   It is a min heap or a max heap. 
   It provides a wrapper for another data structure and provides a queue like interface.
   Its a FIFO data structure, unlike stack, opposite of stack.
   as we know in every subtree, the parent node is min or max.

   The comparison operator < handles different cases. Let's assume we compare
    left < rightÂ and left and right are pairs.
    1. The left.first != right.first, then it returns left.first <right.first.
    2. The left.first == right.first, then it returns left.second <right.second.
   
*/

#include<iostream>
#include<tuple>
#include<string>
#include<queue>//priority_queue

using namespace std;
int main()
{
   using pair_type=pair<int,string>;
   priority_queue<pair_type> q;
   initializer_list<pair_type> l1={{0,"watch swami Mukuntananda"},{1,"Clean House"},{1,"Study Modern C++"},{9, "Read about Hinduism/Bhagwat Gita/Computers fundamentals"},{4,"Problem Solving"},{5,"Have Food"},{0,"Meditate/pranayama"},{7,"Talk with TISA friends/family"},{10,"Singing"},{2,"Positive affirmations!!"}};

   for(const auto& i:l1)//we are passing the reference to each item into the priority queue.i.e the memory footprint of each item.
     q.push(i);

    while(!q.empty())
    {cout<<q.top().first<<" "<<q.top().second<<"\n";q.pop();}
    cout<<"\n";
}