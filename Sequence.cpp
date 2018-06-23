#include<iostream>
#include<string>
#include<fstream>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
    ifstream in;
    in.open(filename);
    if(in.is_open())
    {
      while(!in.eof())
           in>>s;
    }
    in.close();
}

Sequence::~Sequence()
{
}

int Sequence::length()
{
    int num=s.length()%101;
    for(int i=1; i<num; i++)
    {
       s2=s.erase(i*100,1);
    }
    n=s2.length();
    cout<<"length:"<<endl;
    cout<<n<<endl;
} 

int Sequence::numberOf(char base)
{
   int a=0;
   if(base=='A')
   {
     for(int i=0;i<n;i++)
     {
        if(s[i]=='A')
         a++;
     }
   }

   if(base=='T')
   {
     for(int i=0;i<n;i++)
     {
        if(s[i]=='T')
          a++;
     }
   }

   if(base=='C')
   {
     for(int i=0;i<n;i++)
     {
        if(s[i]=='C')
          a++;
     }
   }
   
   if(base=='G')
   {
     for(int i=0;i<n; i++)
     {
        if(s[i]=='G')
          a++;
     }
   }

    cout<<"the number of "<<base<<" is: "<<endl;
    cout<<a<<endl;
}

string Sequence::longestConsecutive()
{

}

string Sequence::longestRepeated()
{

}
