// https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

void insertAtBottom(stack<int> &stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertAtBottom(stack, x);
    stack.push(num);
}

void solve(stack<int> &stack){
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    solve(stack);

    insertAtBottom(stack, num);    
}

void reverseStack(stack<int> &stack) {
    solve(stack);
}