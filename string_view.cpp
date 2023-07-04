/*
  Date: 3rd July, 2023
  string_view is available since c++17.
  It provides a way to pair a pointer with string size().
  It embodies the idea for having a reference type for arrays of data.
  
  Problem: traditionally if you want to pass a c style string object to some C style functions,
  it does not have length information. string_view fills that gap.

  substr requires string pointer and length. 

  We can call a function that accepts a string_view argument with basically anything 
  that is string like in the sense that it stores  characters in a contiguous way.
 
  No copy of the underlying string was made in any of our print calls. so it avoids unnecessary 
  heap allocations or copying. 

  Caveat with string_view: it drops the assumption that strings are zero terminated.

  
  

*/

#include<iostream>
#include<string_view>
  
using namespace std;

void print(string_view sv)
{
 const char* whitespace{"\t\n "};//characters can be in any order
 const auto first{sv.find_first_not_of(whitespace)};
 sv.remove_prefix(min(first,sv.size()));

 const auto last{sv.find_last_not_of(whitespace)};
 if(last!=string_view::npos)
   sv.remove_suffix(sv.size()-last-1); 
 cout << "length: " << sv.length()<< " [" << sv << "]\n";
}

int main(int iargs,char* argv[])
{
   print(argv[0]);//name of the file
   print({});//empty string, implicit argument deduction
   print("a const char * array");//static array C style, implicit conversion to string_view
   print("an std::string_view literal"sv);//string view object
   print("an std::string instance"s);//string object,implicit conversion to string_view
   print(" \t\n foobar \n \t ");

   /*The following string is not zero terminated. string_view can handle it if we give the size. */
   char cstr[] {'a', 'b', 'c'};
   print(string_view(cstr, sizeof(cstr)));
   
}