// https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void sort(stack<int> &stack, int num){
	if(stack.empty()){
		stack.push(num);
		return;
	}

	if(num < stack.top()){
		int top = stack.top();
		stack.pop();
		sort(stack, num);
		stack.push(top);
	}
	else{
		stack.push(num);
	}
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sort(stack, num);
}