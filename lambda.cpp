/*
  Date: 21st June, 2023
  Motivation: Learn Lambda 

*/

/*

 C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of code 
 that are not going to be reused and therefore do not require a name. 
 In their simplest form a lambda expression can be defined as follows:
 
 [ capture clause ] (parameters) -> return-type  
 {   
   definition of method   
 } 

 A lambda expression can have more power than an ordinary function by having access to variables from 
 the enclosing scope. We can capture external variables from the enclosing scope in three ways : 
     Capture by reference 
     Capture by value 
     Capture by both (mixed capture)

    Syntax used for capturing variables : 
      [&] : capture all external variables by reference 
      [=] : capture all external variables by value 
      [a, &b] : capture a by value and b by reference
    A lambda with an empty capture clause [ ] can only access variables which are local to it. 

     
    C++ 14 buffed up lambda expressions further by introducing what’s called a generalized lambda.
    
   
    In c++11, for different data types you could define lambda like this:
    template<typename T>
      [](T a, T b) -> T { return a + b };
 
   But in c++14, you can use the keyword auto
   [](auto a, auto b) { return a + b; }
    
    
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void printVector(vector<int> v)
{
   
   for_each(v.begin(),v.end(),[](int i){cout<<i<<" ";  });
   cout<<endl;
}

int main()
{
   vector<int> v{1,2,5,10,45,89,102,504};
   printVector(v);

   vector<int>::iterator p=find_if(v.begin(),v.end(),[](int i){return i>100;});
   cout<<"Numbers Greater than 100: ";
   while(p!=v.end())
   {
     cout<<*p++<<" ";
   }
   cout<<"\n";
    // function to sort vector, lambda expression is for sorting in non-increasing order.
    //Compiler can make out return type as bool, but shown here just for explanation

    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });
    printVector(v);

   int count_50=count_if(v.begin(),v.end(),[](int i){return i>50;});
   cout<<"\nNumber of numbers greater than 50: "<<count_50<<"\n";
   
    cout<<"\n************Lambda /Capture external variable by reference********\n";
   auto push_into=[&](int i){v.push_back(i);};
   push_into(102);
   push_into(-40);
   
   printVector(v);
    
   cout<<"\n************Lambda /Capture external variable by value********\n";
   // access v1 by copy
    [=]()
    {
        for (auto p = v.begin(); p != v.end();p++ )
        {
            cout << *p << " ";
        }
    };

    int N=70;
   // function to count numbers greater than or equal to N
    // [=] denotes,   can access all variable
    int count_N = count_if(v.begin(), v.end(), [=](int a)
    {
        return (a >= N);
    });
 
    cout << "The number of elements greater than or equal to 70 is : "
         << count_N << endl;

     cout<<"\n**************Generalised Lambda c++14********** \n";
   
     auto sum=[](auto a, auto b){ return a+b;};
     cout<<sum(1,6)<<"\n";
     cout<<sum(0.5,1.5)<<"\n";
     cout<<sum(string("Geek"),string("ForGeeks"))<<"\n";
    

   return 0;
}