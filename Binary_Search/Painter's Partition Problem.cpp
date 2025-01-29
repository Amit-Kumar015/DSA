// https://www.naukri.com/code360/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

bool isPossible(vector<int> &boards, int k, int n, int mid){
    int boardLength = 0;
    int painter = 1;

    for(int i=0; i<n; i++){
        if(boardLength + boards[i] <= mid){
            boardLength += boards[i];
        }
        else{
            painter++;
            
            if(painter > k || boards[i] > mid){
                return false;
            }
            boardLength = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    int n = boards.size();

    for(int i=0; i<n; i++){
        sum += boards[i];
    }
    int e=sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s <= e){
        if(isPossible(boards, k, n, mid)){
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