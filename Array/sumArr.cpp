#include <iostream>
using namespace std;

int sum(int a[], int size){
    int s=0;

    for (int i = 0; i < size; i++)
    {
        s += a[i];    
    }
    
    return s;
}

int main(){
    int a[5]= {1,4,6,2,7};

    cout<<sum(a, 5)<<endl;

    return 0;
}