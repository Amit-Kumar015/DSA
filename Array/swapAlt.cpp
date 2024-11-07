#include <iostream>
using namespace std;

void swapAlt(int a[], int size){
    for (int i = 0; i < size; i+=2)
    {
        if(i+1 < size){
            swap(a[i], a[i+1]);
        }
    }
    
}

void print(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int even[6]= {1, 4, 12, 7, 55, 0};
    int odd[5]= {33, 11, 10, 3, 9};

    swapAlt(even, 6);
    swapAlt(odd, 5);

    print(even, 6);
    print(odd, 5);
    return 0;
}