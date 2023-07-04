/*
    Date: 4th July, 2023
    Reading from standard input.

    Reference: Jacek Golackwiz, c++17 STL
    https://en.cppreference.com/w/cpp/io/basic_istream/ignore
    https://en.cppreference.com/w/cpp/io/basic_istream/getline


    status :Tested
    topics Needs to be explored more.

*/

#include<iostream>
#include<limits>
#include<sstream>
using namespace std;

int main()
{
   double y;int x;
   cout<<"Please Enter two numbers: ";
   if(cin>>x>>y)
     cout<<"\nYou Entered: x= "<<x<<" y= "<<y;
   else
   {
       cout<<"OOPS something went wrong!!";
       cin.clear();//clear the fail state stored in cin

       /*we specify that we are dropping the maximum number of characters until we finally see a newline character, which is also
dropped.*/

       cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//drop all inputs until now
   }

     cout << "now please enter some "
                "comma-separated names:\n> ";

     /*cin first flush all the whitespace(ws), which lead before the next non-whitespace character and after the last comma.getline takes a string reference as an output parameter, and a delimiter character. By default, the delimiter
character is the newline symbol. Here, we defined it to be the comma (,)*/

     for (string s; getline(cin >> ws, s, ',');) //getline accepts a stream object like cin as input
     {
         if (s.empty())
           { break; }
           cout << "name: \"" << s << "\"\n";
     } 
          
}