// /*
// Write a program to sort the elements in odd positions in descending order and elements in ascending order

// Eg 1: Input: 13,2 4,15,12,10,5
//         Output: 13,2,12,10,5,15,4
// Eg 2: Input: 1,2,3,4,5,6,7,8,9
//         Output: 9,2,7,4,5,6,3,8,1
// */

// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     char ch[100];
//     int n;
//     cin >> ch;
//     cout << *(0+ch);
// }

#include <iostream>
using namespace std;
class HelloWorld
{
public:
        //Constructor
        HelloWorld()
        {
                cout << "Constructor is called" << endl;
        }
        //Destructor
        ~HelloWorld()
        {
                cout << "Destructor is called" << endl;
        }
        //Member function
        void display();
};
void HelloWorld ::display()
{
        cout << "Hello World!" << endl;
}
int main()
{
        // //Object created
        // HelloWorld obj1;
        // //Member function called
        // obj1.display();
        int i = 1;
        int j = ++i;
        cout << j;
        i = 1;
        j = i++;
        cout << j;

        return 0;
}