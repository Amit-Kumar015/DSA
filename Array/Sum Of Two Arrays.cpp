// https://www.naukri.com/code360/problems/sum-of-two-arrays_893186?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_4&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void reverse(vector<int> &ans){
	int i = 0;
	int j = ans.size()-1;

	while(i <= j){
		swap(ans[i], ans[j]);
		i++;
		j--;
	}
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	vector<int> ans;
	int carry=0;
	int i = n-1;
	int j = m-1;

	while(i >= 0 && j >= 0){
		int sum = a[i] + b[j] + carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
		i--;
		j--;
	}

	while(i >= 0){
		int sum = a[i] + carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
		i--;
	}

	while(j >= 0){
		int sum = b[j] + carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
		j--;
	}

	if(carry == 1){
		ans.push_back(carry);
	}

	reverse(ans);
	return ans;
}