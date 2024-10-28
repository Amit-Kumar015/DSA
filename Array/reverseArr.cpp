#include <iostream>
using namespace std;

void printArr(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void reverse(int a[], int size){
    int start= 0;
    int end= size-1;

    while(end > start){
        swap(a[start], a[end]);
        start++;
        end--;
    }
}

int main(){
    int a[6]= {2, 4, 8, 1, 0, 1};

    printArr(a, 6);

    reverse(a, 6);

    printArr(a, 6);
    return 0;
}