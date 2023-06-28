/*
  * Date:13th June,2023
  * 
    Write a complete sentence which answers completely who, what, when, why. 
    How to make a line smart, objective, measurable.
    Check each line on a gold mine.
    How to wrtie a resume with smart goals. 
    See what other people have done on linkedin.
    It should look well refined.
    If you can make a fabulous resume, half of your problem will be solved. 
    It should be a story of your life. Its about entering the door. My resume is something i can push through the door.
    

    Write some interview questions: one line answers
    1. Tell me about yourself. You are leading the conversation.
    2. What experience do you have in coaching teams.
    3. 
*/

#include<iostream>
#include<thread>
#include<mutex>

std::mutex m1;
int buffer=0;

void task1(const char* threadNumber, int loopFor)
{
   m1.lock();
   for(int i=0;i<loopFor;++i)
   {
      buffer++;
      std::cout<<threadNumber<<buffer<<std::endl;
      
   }
   m1.unlock();

}
/*
 * 1. Its a very light weight wrapper for owning a mutex on scope basis.
 * 2. It acquires mutex lock the moment you create the object of lock_guard.
 * 3. It automatically removes the lock while goes out of scope.
 * 4. You can not explicitly unlock the lock guard.
 * 5. You can copy the lock_guard.
*/
void task2(const char* threadNumber, int loopFor)
{
   std::lock_guard<mutex>lock(m1);
   for(int i=0;i<loopFor;++i)
   {
     buffer++;
     std::cout<<threadNumber<<buffer<<std::endl;
   }
}

int main()
{
   thread t1(task,"T0",10);
   thread t2(task,"T1",10);
   t1.join();
   t2.join();
   return 0;
}