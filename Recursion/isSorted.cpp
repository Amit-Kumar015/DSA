#include <iostream>
using namespace std;

bool isSorted(int a[], int n){
    if(n == 1){
        return true;
    }

    if(a[n-2] > a[n-1]){
        return false;
    }
    return isSorted(a, n-1);
}

int main(){
    int even[6] = {2,4,6,8,12,32};
    int odd[5] = {4,12,23,56,66};

    cout<<isSorted(even, 6);
    cout<<isSorted(odd, 6);

    return 0;
}