// https://www.naukri.com/code360/problems/check-palindrome_920555?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

bool isPalindrome(string &s){
	int i=0;
	int j=s.length()-1;

	while(i < j){
		if(s[i] == s[j]){
			i++;
			j--;
		}
		else{
			return false;
		}
	}
	return true;
}

bool isBinaryPalindrome(long long N){
	string binary = "";
	while(N > 0){
		binary = (N%2 == 0 ? "0":"1") + binary;
		N /= 2;
	}

	return isPalindrome(binary);
}

bool checkPalindrome(long long N)
{
	// Write your code here.
	return isBinaryPalindrome(N);
}