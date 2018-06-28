#include<iostream>
#include<string>
#include"Sequence.h"
#include<time.h>
using namespace std;

int main()
{
    clock_t start,finish;
    double totaltime;
    start=clock();

    Sequence obj("dna.txt");
    cout<<"length :"<<endl;
    cout<<obj.length()<<endl;
    cout<<"number :"<<endl;
    cout<<obj.numberOf('A')<<endl;
    cout<<"the longest consecutive :"<<endl;
    cout<<obj.longestConsecutive()<<endl;
    cout<<"the longest repeated :"<<endl;
    cout<<obj.longestRepeated()<<endl;
   
    finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<totaltime<<endl;
  
    return 0;
}
