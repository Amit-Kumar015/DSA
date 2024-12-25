#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int k){
    int s=0;
    int e= size-1;

    int mid= s + (e-s)/2;

    while(s <= e){
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid] > k){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }

    return -1;
}

int main(){
    int even[6] = {2,4,6,8,12,32};
    int odd[5] = {4,12,23,56,66};

    cout<<binarySearch(even, 6, 12);
    cout<<binarySearch(odd, 5, 4);
    return 0;
}