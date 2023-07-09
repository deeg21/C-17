/*
   Date: 9 July, 2023
   Jacek Galowicz
   sorting containers
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<random>

using namespace std;

static void print(vector<int> v)
{
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
   cout<<"\n";

     
}
int main()
{
   vector<int> v{1,2,3,-8,10,100,10000};
   
   sort(v.begin(),v.end());
   print(v);
 
   random_device rd;
   std::mt19937 g(rd());

   std::shuffle(v.begin(),v.end(),g);
   print(v);

   cout<<is_sorted(v.begin(),v.end())<<"\n";

   partition(v.begin(),v.end(),[](int x){return x>5; });
   print(v);

   auto middle (next(begin(v), int(v.size()) / 2));
   partial_sort(v.begin(),middle,v.end());
   print(v);

   struct mystruct
   {
     int a;
     int b;
   };
   vector<mystruct> mv {{5, 100}, {1, 50}, {-123, 1000},{3, 70}, {-10, 20}};
   sort(mv.begin(),mv.end(),[](const mystruct& lhs,const mystruct& rhs){return lhs.b<rhs.b;});
   //print(v);

   for(const auto& [a,b]:mv)
   { cout << "{" << a << ", " << b << "} ";}
cout << '\n';
}