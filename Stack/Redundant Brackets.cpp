// https://www.naukri.com/code360/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' ||
            ch == '*' || ch == '/'){
            
            st.push(ch);
        }
        else{
            if(ch == ')'){
                bool isReduntant = true;
                while(st.top() != '('){
                    char top = st.top();

                    if(top == '+' || top == '-' ||
                        top == '*' || top == '/'){

                        isReduntant = false;
                    }
                    st.pop();
                }
                
                if(isReduntant){
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}
