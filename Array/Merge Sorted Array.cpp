// https://leetcode.com/problems/merge-sorted-array/description/

class Solution
{
public:
    // optimised
    class Solution
    {
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;

            while (j >= 0)
            {
                if (i >= 0 && nums1[i] > nums2[j])
                {
                    nums1[k] = nums1[i];
                    i--;
                    k--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            }
        }
    };

    // void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    // {
    //     vector<int> ans;
    //     int i = 0, j = 0;

    //     while (i < m && j < n)
    //     {
    //         if (nums1[i] < nums2[j])
    //         {
    //             ans.push_back(nums1[i]);
    //             i++;
    //         }
    //         else
    //         {
    //             ans.push_back(nums2[j]);
    //             j++;
    //         }
    //     }

    //     while (i < m)
    //     {
    //         ans.push_back(nums1[i]);
    //         i++;
    //     }
    //     while (j < n)
    //     {
    //         ans.push_back(nums2[j]);
    //         j++;
    //     }

    //     nums1 = ans;
    // }
};