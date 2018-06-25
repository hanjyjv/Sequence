#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
    ifstream inf;
    inf.open(filename.data());
    while(!inf.eof())
    {
        getline(inf,s);
        s2+=s;
    }
    inf.close();
}

Sequence::~Sequence()
{
}

int Sequence::length()
{
    n=s2.length();
    cout<<"length:"<<endl;
    cout<<n<<endl;
} 

int Sequence::numberOf(char base)
{
    int acount=0;
    int tcount=0;
    int ccount=0;
    int gcount=0;

    for(int i=0;i<n;i++)
    {
        switch(s2[i])
        {
            case 'A':
                acount++;
                break;
            case 'T':
                tcount++;
                break;
            case 'C':
                ccount++;
                break;
            case 'G':
                gcount++;
                break;
            default:
                cout<<"False!"<<endl;
                break;
        }
    }
    
    if(base=='A')
        cout<<"A: "<<acount<<endl;
    if(base=='T')
        cout<<"T: "<<tcount<<endl;
    if(base=='C')
        cout<<"C: "<<ccount<<endl;
    if(base=='G')
        cout<<"G: "<<gcount<<endl;

}

string Sequence::longestConsecutive()
{
    int now=0;
    int max=-1;
    string s3;

    for(int i=0;i<n;i++)
    {
        if(s2[i]==s2[i+1])
        {
            now++;
        }
        else
        {
            now++;
            
            if(now>max)
            {
                max=now;
                s3=s2[i];
            }
            
            now=0;
        }
    }
    
    for(int i=0;i<max-1;i++)
        cout<<s3;
    cout<<s3<<endl;
}

string Sequence::longestRepeated()
{
    
}
