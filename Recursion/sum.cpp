#include <iostream>
using namespace std;

int sum(int a[], int n, int s){
    if(n == 0){
        return s; 
    }

    s += a[0];
    return sum(a+1, n-1, s);
}

int main(){
    int s=0;
    int a[7] = {2,4,6,8,12,32,100};

    cout<<sum(a, 7, s);
    return 0;
}