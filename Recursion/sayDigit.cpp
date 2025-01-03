#include <iostream>
using namespace std;

void say(int n){
    string a[10] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};

    if(n == 0){
        return;
    }

    int remaningDigit = n/10;
    say(remaningDigit);
    
    int digit = n%10;
    cout<<a[digit];
}

int main(){
    int n=134;
    
    say(n);
    return 0;
}