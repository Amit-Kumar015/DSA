// https://www.naukri.com/code360/problems/reverse-the-string_799927?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void reverse(string &str, int i, int j){
	if(i > j){
		return ;
	}

	swap(str[i], str[j]); 
	reverse(str, i+1, j-1);
}

string reverseString(string str)
{
	// Write your code here.
	reverse(str, 0, str.length()-1);
	return str;
}