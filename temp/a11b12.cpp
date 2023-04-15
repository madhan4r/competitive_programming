/*
Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd
The number varies from 1 to 99.
*/

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[100], ch, count = '1';
    cout << "enter the characters and numbers" << endl;
    cin >> s;
    // for (int i = 0; i < strlen(s); i++)
    // {
    //     if (s[i] >= '0' && s[0] <= '9')
    //     {
    //         if (count >= '0')
    //         {
    //             count += s[i];
    //         }
    //     }
    //     else
    //     {
    //         if (count)
    //         {
    //             cout << string(count, ch);
    //             count;
    //         }
    //         ch = s[i];
    //     }
    // }
    cout << count;
    cout << string(count, 'G');
}