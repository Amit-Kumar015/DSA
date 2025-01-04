#include <iostream>
using namespace std;

int search(int a[], int n, int k, int index=0){
    if(index == n){
        return -1;
    }

    if(a[index] == k){
        return index;
    }

    return search(a, n, k, index+1);
}

int main(){
    int even[6] = {2,4,6,8,12,32};
    int odd[5] = {4,12,23,56,66};

    cout<<search(even, 6, 12);
    cout<<search(odd, 5, 23);
    return 0;
}