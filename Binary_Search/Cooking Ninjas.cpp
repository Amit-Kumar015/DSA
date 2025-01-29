// https://www.naukri.com/code360/problems/cooking-ninjas_1164174?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

bool isPossible(vector<int> &rank, int m, int mid){
    int meal = 0;
    int time = 0;

    for(int i=0; i<rank.size(); i++){
        int j=1;
        time = 0;
        
        while(time + j*rank[i] <= mid){
            meal++;

            if(meal >= m){
                return true;
            }
            time += rank[i]*j;
            j++;
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(), rank.end());
    int s=0;
    int e=rank[0]*(m*(m+1))/2;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(isPossible(rank, m, mid)){
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
