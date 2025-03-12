// https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void heapify(vector<int>& arr, int size, int index){
    int smallest = index;

    int leftIndex = 2*index + 1;
    int rightIndex = 2*index + 2;

    if(leftIndex < size && arr[smallest] > arr[leftIndex]){
        smallest = leftIndex;
    }
    
    if(rightIndex < size && arr[smallest] > arr[rightIndex]){
        smallest = rightIndex;
    }

    if(smallest != index){
        swap(arr[smallest], arr[index]);
        heapify(arr, size, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int size = arr.size();

    for(int i = size/2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }

    return arr;        
}
