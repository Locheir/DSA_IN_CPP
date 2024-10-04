#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100];
    // The commented line below will not work 
    // as we are trying to assign a string literal 
    // to a char array which is not possible
    //str1 = "Hello World";


    // strcpy(destination, source) : used to copy a string.
    strcpy(str1, "Hello World");
    cout << str1 << endl;
    
    //strcat(str1, str2) : used to concatenate string1 with string2.
    char st1[100] = "mohit";
    char st2[100]= "gupta";
    strcat(st1, st2);
    cout <<st1 << endl;
    
    //strcmp(str1, str2) : used to compare two strings.
    char s1[100] = "abcd";
    char s2[100] = "abcd";

    cout << strcmp(s1,s2) << endl;

    char s3[100] = "xyz";
    char s4[100] = "abc";
    cout << strcmp(s3,s4) << endl;
    cout << strcmp(s4,s3) << endl;
    return 0;
}