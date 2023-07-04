/*
   Date: 3rd July, 2023
   Understand the working of c++ strings and string_view.
   Also use ostream.
   Reference: Jacek Golawickz, C++17 STL. Page 313-319.
   
   
   string_view (c++17)

   string_view can be converted to string object(automatically terminates a null to string_view). and then mixed with string objects.
   string_view are not zero terminated by default, so buffer overflow can occur if you are not careful.
   

  The std::stringstream, std::ostringstream, and std::istringstream classes are much better suited for string concatenation and parsing, as they enhance the memory management
while appending, and provide all the formatting features we know from streams in general.

*/

#include<iostream>
#include<sstream>
#include<string_view>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
   /*The constructor will copy the string argument to its buffer.*/

   string a{"a"};//static array containing characters to string object
   auto  b{"b"s};//creates a string object on the fly


  /*In order to avoid a copy we can use string buffer.*/
  string_view c{"c"};
  auto d{"d"sv};//create a string_view object on the fly.

  cout<<a<<","<<b<<'\n';
  cout<<c<<","<<d<<'\n';

  cout << a + b << '\n';
  cout << a + string{c} << '\n';

 
  ostringstream o;//takes all string, string_view objects and prints them into a string buffer.
  o << a << " " << b << " " << c << " " << d;//stream all string objects to ostream.
  auto concatenated_var (o.str());//construct a new string object with o.str();
  cout << concatenated_var << '\n';


  /***A string is basically also an iterable container object with char items. std::transform can be used on the string container along with toUpper() from C library. */
   transform(begin(concatenated_var),end(concatenated_var),begin(concatenated_var),::toupper);
   cout<<concatenated_var<<"\n";

   
}