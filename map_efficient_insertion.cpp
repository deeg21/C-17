/*
   Date: 27th June,2023
   Reference: Jacek Galowickz

   
   
*/

#include<iostream>
#include<list>
#include<map>
#include<functional>//????

using namespace std;

struct billionaire
{
   string name;
   double dollars;
   string country;
}

int main()
{
   list<billionaire> list_billionaires
  {
              {"Bill Gates", 86.0, "USA"},
              {"Warren Buffet", 75.6, "USA"},
              {"Jeff Bezos", 72.8, "USA"},
              {"Amancio Ortega", 71.3, "Spain"},
              {"Mark Zuckerberg", 56.0, "USA"},
              {"Carlos Slim", 54.5, "Mexico"},
              
              {"Bernard Arnault", 41.5, "France"},
              {"Liliane Bettencourt", 39.5, "France"},
              {"Wang Jianlin", 31.3, "China"},
              {"Li Ka-shing", 31.2, "Hong Kong"}

   };

   //map each country(key) to the richest billionaire on that country along iwth his fortune in dollars. 

  map<string, pair<const billionaire,size_t>> m;
   
  /*
    std::pair<iterator, bool> try_emplace(const key_type& k, Args&&...T)
    The key being inserted is parameter k and the associated value is constructed from the parameter pack args.
    If we succeed in inserting the item, then the function returns an iterator, which points to the new node in
    the map, paired with a Boolean value being set to true. If the insertion was not successful, the Boolean value 
    in the return pair is set to false, and the iterator points to the item with which the new item would clash.

    This characteristic is very useful in our case--when we see a billionaire from a specific country for the first time, 
    then this country is not a key in the map yet. In that case, we must insert it, accompanied with a new counter being
    set to 1. If we did see a billionaire from a specific country already, we have to get a reference to its existing counter, 
    in order to increment it.

   Note that both the insert and emplace functions of std::map work exactly the same way. A crucial difference is that
   try_emplace will not construct the object associated with the key if the key already exists. This boosts the performance in
   case objects of that type are expensive to create.
 */

   for(const auto &b:list_billionaires)
     auto [iterator, success] = m.try_emplace(b.country, b, 1);
    if (!success) 
    {
             iterator->second.second += 1;
    }
    
    for (const auto & [key, value] : m) 
    {
      const auto &[b, count] = value;
      cout << b.country << " : " << count<< " billionaires. Richest is "<< b.name << " with " << b.dollars<< " B$\n";
    }

}