#include<iostream> 
#include<ctype.h>
#include<string>

using namespace std;

int main()
{

    string str;

    getline(cin,str);

    int i;
    int count=0;
    int l=str.length();

    for(i=1;i<l-1;i++)
    {
        if(toupper(str.at(i))=='A')
            if(str.at(i-1)==' ' && str.at(i+1)==' ')
                    count++;
    }

    if(toupper(str.at(0))=='A' && str.at(1)==' ')
        count++;

    if(toupper(str.at(l-1))=='A' && str.at(l-2)==' ')
        count++;

    cout<<"Count is "<<count<<endl;
    return 0;

}