#include <iostream>
using namespace std;

void  merge(int a[], int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy value
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = a[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = a[mainArrayIndex++];
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            a[mainArrayIndex++] = first[index1++];
        }
        else{
            a[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        a[mainArrayIndex++] = first[index1++];
    }
    
    while(index2 < len2){
        a[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int a[], int s, int e){
    if(s >= e){
        return ;
    }

    int mid = s + (e-s)/2;

    // left part sort krna h
    mergeSort(a, s, mid);

    // right part sort krna h
    mergeSort(a, mid+1, e);

    // merge
    merge(a, s, e);
}

int main(){
    int a[6] = {2,12,4,0,1,9};
    int n=6;
    

    mergeSort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}