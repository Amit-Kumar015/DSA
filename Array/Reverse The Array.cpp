// https://www.naukri.com/code360/problems/reverse-the-array_1262298?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio3&leftPanelTabValue=PROBLEM

void reverseArray(vector<int> &arr , int m) {
    // Write your code here 
    int i=m+1;
    int j=arr.size()-1;

    while(i < j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

}