// memprisation
int f(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main(){
    int n=5;
    vector<int> dp(n+1, -1);
    cout<<f(n, dp);
}

// tabulation
int f(int n, vector<int> &dp){
    dp[0] = 0, dp[1] = 1;

    for(int i=0; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}

int main(){
    int n=5;
    vector<int> dp(n+1, -1);
    cout<<f(n, dp);
}

// memory optimisation
int f(int n){
    int prev2 = 0, prev = 1;

    for(int i=0; i<=n; i++){
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main(){
    int n=5;
    cout<<f(n);
}