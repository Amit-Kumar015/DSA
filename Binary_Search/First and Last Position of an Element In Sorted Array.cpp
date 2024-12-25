// https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

int firstoccu(vector<int>& arr, int n , int k){
    int s=0, e=n-1;
    int mid=s+ (e-s)/2;
    int ans=-1;

    while(e>=s){
        if(k==arr[mid]){
            ans=mid;
            e=mid-1;
        }

        else if(k> arr[mid]){
            s=mid+1;
        }

        else{
            e=mid-1;
        }
        mid=s+ (e-s)/2;
    }
    return ans;
}

int lastoccu(vector<int>& arr, int n , int k){
    int ans2=-1;
    int s=0, e=n-1;
    int mid=s+ (e-s)/2;

    while(e>=s){
        if(k==arr[mid]){
            ans2=mid;
            s=mid +1;
        }

        else if(k> arr[mid]){
            s=mid+1;
        }

        else{
            e=mid-1;
        }
        mid=s+ (e-s)/2;
    }
    return ans2;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
    p.first = firstoccu(arr, n, k);
    p.second= lastoccu(arr, n, k);
    return p;
}
