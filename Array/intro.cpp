#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<' ';
    }
}

int main(){
    // initializing an array
    int a[5]= {1,2,3,4,5};

    // initializing entire array with 0's
    int b[100]= {0};

    // initializing entire array with 0's
    int c[100];
    fill_n(c, 100, 2);

    // rest of the element are 0 when not initialized entire array with value
    int d[10]= {1,2};

    // printing an array
    printArray(a, sizeof(a)/sizeof(a[0]));


    return 0;
}