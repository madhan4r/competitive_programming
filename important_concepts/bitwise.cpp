/*
BITWISE CONCEPTS

Lets take 8 bit as example

1 byte = 8 bits
0 = 00000000
1 = 00000001
2 = 00000010
.....
255 = 11111111


Bitwise AND (&)
1 & 1 = 1
1 & 0 = 0
0 & 1 = 0
0 & 0 = 0

Bitwise OR (OR)
1 | 1 = 1
1 | 0 = 1
0 | 1 = 1
0 | 0 = 0

Bitwise XOR (XOR)
1 ^ 1 = 0
1 ^ 0 = 1
0 ^ 1 = 1
0 ^ 0 = 0

Bitwise left Shift (<<)/p>
31 = 00011111
31 << 1 = 00111110
31 << 2 = 01111100

Normally lets say left shifting means n * 2^k

Bitwise right Shift (>>)
31 = 00011111
31 >> 1 = 00001111
31 >> 2 = 00000111

Normally lets say right shifting means n / 2^k

Bitwise not (~)

~1 = 0
~0 = -1 (00000000 when not used 11111111 (the first bit represents sign (1 means minus) then remaining is set to 2s compliment))

2's compliment
1 =   00000001
            +1
  =   00000010
*/

#include <iostream>
using namespace std;

void findOddOrEven(int n)
{
    // 00000001 (if last number is 1 then its odd)
    // 00000010 (even)
    if (n & 1)
    {
        cout << "The given number is odd" << endl;
    }
    else
    {
        cout << "The given number is even" << endl;
    }
}

int findIthBit(int n, int i)
{
    // 00000101 (To find out 2 index (from last) simply left shift the i from 1 and use & operator)
    int mask_number = (1 << i);
    int result = (n & mask_number) > 0 ? 1 : 0;
    cout << "The ith number is " << result << endl;
    return result;
}
int main()
{
    int n, i;
    cin >> n >> i;
    findOddOrEven(n);
    findIthBit(n, i);
}