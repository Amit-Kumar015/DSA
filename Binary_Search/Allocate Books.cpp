// https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

bool isPossible(int n, int m, vector<int> time, long long mid){
	int dayCount = 1;
	long long chapters = 0;

	for(int i=0; i<m; i++){
		if(chapters + time[i] <= mid){
			chapters += time[i];
		}
		else{
			dayCount++;
			if(dayCount > n || time[i] > mid){
				return false;
			}
			chapters = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long s = 0;
	long long sum = 0;

	for(int i=0; i<m; i++){
		sum += time[i];
	}
	long long e = sum;
	long long mid = s + (e-s)/2;
	long long ans = -1;

	while(s <= e){
		if(isPossible(n, m, time, mid)){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
		mid = s + (e-s)/2;
	}

	return ans;
}