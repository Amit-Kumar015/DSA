#include <iostream>
using namespace std;

int partition(int a[], int s, int e){
    int pivot = a[s];
    int cnt=0;

    for(int i=s+1; i<=e; i++){
        if(a[i] <= pivot){
            cnt++;
        }
    }

    int pivotIndex = s + cnt;
    swap(a[s], a[pivotIndex]);

    int i=s;
    int j=e;
    while(i < pivotIndex && j> pivotIndex){
        while(a[i] < pivot) i++;

        while(a[j] > pivot) j--;

        if(i < pivotIndex && j> pivotIndex){
            swap(a[i], a[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int a[], int s, int e){
    // base case
    if(s >= e){
        return;
    }

    // partition
    int p = partition(a, s, e);

    // left part sort
    quickSort(a, s, p-1);

    // right part sort
    quickSort(a, p+1, e);
}

int main(){
    int a[10] = {3,1,6,4,2,10,0,20,12,7};
    int n=10;

    quickSort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}