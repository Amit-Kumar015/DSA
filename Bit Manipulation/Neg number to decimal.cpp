#include <iostream>
#include <math.h>
using namespace std;

void binToDec(int n)
{
    n = -n; // Make positive for now
    // Step 1: Convert to binary
    for (int i = bits - 1; i >= 0 && n > 0; i--)
    {
        binary[i] = n % 2;
        n /= 2;
    }

    // Step 2: Take 1's complement (invert bits)
    for (int i = 0; i < bits; i++)
    {
        binary[i] = 1 - binary[i];
    }

    // Step 3: Add 1 (2's complement)
    for (int i = bits - 1; i >= 0; i--)
    {
        if (binary[i] == 0)
        {
            binary[i] = 1;
            break;
        }
        else
        {
            binary[i] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "enter the nber: " << endl;
    cin >> n;
}