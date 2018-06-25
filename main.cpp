#include<iostream>
#include<string>
#include"Sequence.h"
using namespace std;

int main()
{
  Sequence obj("dna.txt");
  obj.length();
  obj.numberOf('A');
  obj.longestConsecutive();
  
  return 0;
}
