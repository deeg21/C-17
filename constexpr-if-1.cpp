/*

*/
/*
* Date:15th June,2023.
* use of constexpr in if statement. The functions below will not compile if we remove the constexpr from if statement.
* Reason being, a new copy of each function is generated, at runtime, according to type provided in argument.
* value.length() does not exist for an integer, so the code will not compile.
* a constexpr, determines the type at compile time, and chooses only the if statement part if the argument is integer.
*/

#include<string>
#include<type_traits>
#include<iostream> 
#include<numeric_limits>
//using namespace std;

template <typename T>
auto length(T const& value)
{
   if constexpr(std::is_integral<T>::value)
   {
     return value;
   }
   else
   {
      
     return value.length();
   }

}
/*
  This function does not require constexpr. 
*/
template<typename T>
void print_type_info1(const T& )
{
   if (std::is_integral<T>::value)
    std::cout<<"is integral"<<"\n";
   else
    std::cout<<"is not integral"<<"\n";
}

template<typename T>
auto print_type_info2(const T&t )
{
   if constexpr (std::is_integral<T>::value && !std::is_same<bool,T>::value)
    return t+1;
   else if constexpr(std::is_floating_point<T>::value)
    return t+0.1;
   else return t;
    
}

int main()
{
    int n{10};
    std::string s{"abc"};
   
    std::cout<<"n="<<n<<" and length = "<<length(n)<<std::endl;
    std::cout<<"s="<< s <<" and length = "<<length(s)<<std::endl;

   print_type_info1(5);
   print_type_info1(2.3);

   std::cout<<print_type_info2(5)<<"\n";
   std::cout<<print_type_info2(2.3);
   std::cout<<print_type_info2(true)<<"\n";
  
    return 0;
}