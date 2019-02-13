#include <stdio.h>
02
#include <stdlib.h>
03
 
04
struct freq
05
{
06
    char *x[64];
07
    int y;
08
};
09
 
10
struct freq array1[100];
11
 
12
int main()
13
{
14
 
15
    FILE * input;
16
    int i,j;
17
    char tempWord[] ="hello";
18
    input = fopen("random.txt","r");
19
 
20
    for (i=0;i<=10;i++) //go through the 10 elements in text file
21
    {
22
        //scan each word into a temporary variable
23
        // **** NOT COMPLETE, JUST USING TEMPWORD ASSIGNED ABOVE TO CHECK WORKING.
24
 
25
        //loop through the existing array to check if the temp value equals a word
26
        // if it does increment the corresponding counter
27
        for(j=0;j<=10;j++){
28
            if(strcmp(array1[j].x, tempWord) == 0){ //if it does equal the scanned word
29
                array1[j].y++; //increment its count
30
            }
31
        }
32
 
33
        //if it doesn't add it to the array
34
 
35
        fscanf(input, "%s",array1[i].x);
36
 
37
        printf("WORD %i: %s ",i,array1[i].x);
38
        printf(" COUNT IS: %i", array1[i].y);
39
        printf("\n");
40
    }
41
 
42
    fclose(input);
43
    return 0;
44
}
