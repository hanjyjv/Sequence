#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<cstring>
#include"Sequence.h"
using namespace std;

int pstrcmp(const void *, const void *);

int common_len(char *,char*);

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
    return n;
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
        return acount;
    if(base=='T')
        return tcount;
    if(base=='C')
        return ccount;
    if(base=='G')
        return gcount;

}

string Sequence::longestConsecutive()
{
    int now=0;
    int max=-1;
    string s3;
    string s4;

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
    
    for(int i=0;i<max;i++)
        s4=s4+s3;

    return s4;
}

char a[2000000];
char *post[2000000];

string Sequence::longestRepeated()
{
    int j;
    int temp;
    int max=0,max_index=0;

    for(int m=0;m<n;m++)
    {
        a[m]=s2[m];
        post[m]=&a[m];
    }

    qsort(post,n,sizeof(char *),pstrcmp);

    for(j=0;j<n-1;j++)
    {
        temp = common_len(post[j],post[j+1]);

        if(max<temp)
        {
            max=temp;
            max_index=j;
        }
    }

    string s5;

    for(int m=0;m<max;m++)
    {
        s5+=(*post[max_index]);
        post[max_index]++;
    }

    return s5;

}

int pstrcmp(const void *p1,const void *p2)
{
    return strcmp(*(char**)p1, *(char**)p2);
}

int common_len(char *p,char *q)
{
    int k=0;

    while(p!=NULL&&q!=NULL&&(*p == *q))
    {   p++;
        q++;
        k++;
    }

    return k;
}
