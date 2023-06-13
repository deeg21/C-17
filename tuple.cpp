/*
* Date: 13th June,2023
* Tuple: A tuple is a fixed size collection of heterogenous elements. 
         Its a generalisation of a pair.
*  structured bindings only available with '-std=c++17' or '-std=gnu++17'
* Reference: https://en.cppreference.com/w/cpp/utility/tuple (typed myself, not copied blindly).
*/

#include<iostream>
#include<tuple>
#include<string>
#include<stdexcept>

std::tuple<float,char,std::string> getStudent(int id)
{
   switch(id)
   {
     case 0: return {3.8,'A',"Liza Thompson"};
     case 1: return {1.2,'A',"Belizz Miami"};
     case 2: return {0.6,'B',"Merinda Gatos"};
     case 3: return {4.5,'B',"canary bellows"}; 
   }
  throw std::invalid_argument("id");
}

int main()
{
  const auto student0=getStudent(0);
  std::cout<<"ID0: "
           << "GPA: "<<std::get<0>(student0)<<" "
            <<"Grade: "<<std::get<1>(student0)<<" "
            << "Name: "<<std::get<2>(student0)<<"\n";

  const auto student1=getStudent(1);
  std::cout<< "ID1: "
           << "GPA:"   <<std::get<0>(student1)<<" "
           << "Grade:" <<std::get<1>(student1)<<" "
           << "Name: " <<std::get<2>(student1)<<"\n";

  float gpa;
  char grade;
  std::string name;
  std::tie(gpa,grade,name)=getStudent(2);
  std::cout<< "ID2: "
           << "GPA:"   <<gpa<<" "
           << "Grade:" <<grade<<" "
           << "Name: " <<name<<"\n";

  //structured binding c++17
  auto [gpa3,grade3,name3]=getStudent(3);

  std::cout<< "ID3: "
           << "GPA:"   <<gpa3<<" "
           << "Grade:" <<grade3<<" "
           << "Name: " <<name3<<"\n";

return 0;
}