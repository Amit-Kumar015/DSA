#include <iostream>
using namespace std;

void heapify(int arr[], int size, int index){
    int largest = index;

    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;

    if(leftIndex <= size && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    
    if(rightIndex <= size && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int n){
    while(n > 1){
        swap(arr[1], arr[n]);
        n = n-1;

        heapify(arr, n, 1);
    }
}

int main(){
    int arr[6] = {-1, 55, 53, 54, 52, 50};
    int size = 6;

    
    heapSort(arr, size-1);

    for (int i = 1; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}