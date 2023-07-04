/*
   Date:3rd July, 2023
   Remove unwanted whitespaces in between words in a string. Also added @,# as unwanted characters in any order at the beginning and end
   find_first_not_of()
   find_last_not_of()

  also
    find_first_of()
    find_last_of()
   
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>//substr
using namespace std;


/*Trim unwanted whitespaces from a string.
  Whitespace means the character '\t', '\n', ' '.
  string:find_first_not_of(): Returns the first non whitespace character position.
  If there is only whitespace in the string it returns string::npos, i.e empty string. */
string trim_whitespace(const string& s)
{
   const char whitespace[]={" \t\n@#"};//the order of characters can be anything like \t\n, \n\t
   const size_t first{s.find_first_not_of(whitespace)};//returns the first character position in the string with no whitespace..
   if(string::npos==first){return{};}
   const size_t last{s.find_last_not_of(whitespace)};//returns the last character position in the string with no whitespace.
   
    return s.substr(first,last-first+1);//creates a new string in new memory.
}
int main()
{
   string s{"\t\n@#    Sorrounding with ugly "
             "whitespace. @\n#\t"};
   cout << "{" << s << "}\n";
   cout << "{" << trim_whitespace(s)  << "}\n";

   
   
    
}