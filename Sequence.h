#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
#include<string>
using namespace std;

class Sequence
{
public:
    Sequence(string);
    ~Sequence();
    int length();
    int numberOf(char);
    stirng longestConseccutive();
    string longestRepeated();

private:
    int n;
    string filename;
    string s;
    string s2;
    char base;
};

#endif
