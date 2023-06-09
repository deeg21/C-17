
/*
* Date: 9th June 2023.
* Ref Book Author:Jaceq Galowicz, C++17 STL Cookbook,Packt Publishing.
* Automatic template type deduction. The value passed to the constructor is used to infer the template type. 
*  
*/
#include<iostream>

template<typename T1,typename T2,typename T3>
class my_wrapper
{
  T1 t1;
  T2 t2;
  T3 t3;
  public:
   explicit my_wrapper(T1 t1_,T2 t2_,T3 t3_): t1{t1_},t2{t2_},t3{t3_}
   {}
    void display(){std::cout<<"t1: "<<t1<<" t2: "<<t2<<" t3: "<<t3<<"\n";}
};

int main(int iargs,char* args[])
{
    my_wrapper wrapper{1,2.2,"Memo"};//applicable in c++17
    // my_wrapper<int, float, const char*> wrapper{ 1,2.2,"Memo" };//applicable in c++14 and before
    wrapper.display();

}

