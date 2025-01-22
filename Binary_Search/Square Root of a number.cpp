// https://www.naukri.com/code360/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

int floorSqrt(int n)
{
    // Handle edge cases
    if (n == 0 || n == 1) {
        return n;
    }

    int s = 0;
    int e = n;
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        long long square = (long long)mid * mid; // Prevent overflow

        if (square == n) {
            return mid;
        } else if (square > n) {
            e = mid - 1;
        } else {
            ans = mid;
            s = mid + 1;
        }
    }

    return ans;
}
