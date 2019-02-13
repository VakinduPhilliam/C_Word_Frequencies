#include<iostream.h>
#include<fstream.h>
#include<string.h>
 
 
int main()
{
 ifstream fin("my_data.txt"); //opening text file
 int count=0;
 char ch[20],c[20];
 
 cout<<"Enter a word to count:";
 gets(c);
 
 while(fin)
 {
  fin>>ch;
  if(strcmp(ch,c)==0)
   count++;
 } 
 
 cout<<"Occurrence="<<count<<"n";
 fin.close(); //closing file
 
 return 0;
 
}