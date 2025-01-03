#include <iostream>
using namespace std;

int binarySearch(int a[], int s, int e, int k){
    int mid = s + (e-s)/2;
    
    if(a[mid] == k){
        return mid;
    }
    else if(a[mid] < k){
        binarySearch(a, mid+1, e, k);
    }
    else{
        binarySearch(a, s, mid-1, k);
    }
}

int main(){
    int even[6] = {2,4,6,8,12,32};
    int odd[5] = {4,12,23,56,66};

    cout<<binarySearch(even, 0, 6, 12);
    cout<<binarySearch(odd, 0, 5, 4);
    return 0;
}