/*
Write a program to print the following output for the given input. You can assume the string is of odd length
Eg 1: Input: 12345
       Output:
1       5
  2   4
    3
  2  4
1      5
Eg 2: Input: geeksforgeeks
         Output:
g                         s
  e                     k
    e                 e
      k             e
        s         g
          f      r
             o
          f     r
        s         g
      k             e
    e                 e
  e                      k
g                          s 
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char ch[100];
  int n;
  cin >> ch;
  n = strlen(ch);
  // Print all rows one by one
  for (int i = 0; i < n; i++)
  {
    // Print characters of current row
    for (int j = 0; j < n; j++)
    {
      // For i = 0, we print only in
      // first and last columns
      // For i = 1, we print only in
      // second and second last columns
      // In general, we print only in
      // i-th and n - (i + 1) th columns
      if (j == i || j == (n - (i + 1)))
      {
        cout << ch[j];
      }
      else
      {
        cout << " ";
      }
    }
    // Print a newline before printing the
    // next row.
    cout << endl;
  }
  return 0;
}