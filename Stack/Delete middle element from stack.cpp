// https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int count, int size){
   if(count == size/2){
      inputStack.pop();
      return;
   }

   int e = inputStack.top();
   inputStack.pop();
   solve(inputStack, count+1, size);
   inputStack.push(e);
}

void deleteMiddle(stack<int>&inputStack, int N){
   int count = 0;

   solve(inputStack, count, N);   
}