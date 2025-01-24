// https://www.naukri.com/code360/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void solve(string str, vector<string>& ans, int index, string output){
	if(index > str.length()-1){
		if(output.length() > 0){
			ans.push_back(output);
		}
		return;
	}

	// exclude
	solve(str, ans, index+1, output);

	// include
	output.push_back(str[index]);
	solve(str, ans, index+1, output);
}
vector<string> subsequences(string str){
	
	// Write your code here
	string output="";
	vector<string> ans;
	solve(str, ans, 0, output);
	return ans;
}
