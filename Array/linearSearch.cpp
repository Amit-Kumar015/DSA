#include <iostream>
using namespace std;

bool linearSearch(int a[], int size, int key){
    for (int i = 0; i < size; i++)
    {
        if(a[i] == key){
            return true;
        }
    }
    
    return false;
}

int main(){
    int a[10]= {5, 7, -2, 10, 22, -2, 0, 5, 22};

    cout<<linearSearch(a, 10, 1);

    return 0;
}