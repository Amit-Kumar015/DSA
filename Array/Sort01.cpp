#include <iostream>
using namespace std;

void sort01(int arr[], int size){
    int s=0;
    int e=size-1;

    while(s < e){
        if(arr[s] == 1 && arr[e] == 0){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
        else if(arr[e] == 1){
            e--;
        }else{
            s++;
        }
    }
}

void printArr(int a[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[7] = {0,1,1,0,1,0,1};

    printArr(arr, 7);
    sort01(arr, 7);
    printArr(arr, 7);

    return 0;
}