#include <iostream>
using namespace std;

int getMax(int a[], int size){
    int MaxNum= INT_MIN;

    for (int i = 0; i < size; i++)
    {
        // MaxNum= max(MaxNum, a[i]);

        if(MaxNum < a[i]){
            MaxNum= a[i];
        }
    }

    return MaxNum;
}

int getMin(int a[], int size){
    int MinNum= INT_MAX;

    for (int i = 0; i < size; i++)
    {
        // MinNum= min(MinNum, a[i]);

        if(MinNum > a[i]){
            MinNum= a[i];
        }
    }

    return MinNum;
}

int main(){
    int arr[100] = {23, 4, -1, 1, 34, 5, 12};

    cout<<getMin(arr, 100)<<endl;

    cout<<getMax(arr, 100)<<endl;

    return 0;
}