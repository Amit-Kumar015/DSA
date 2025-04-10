// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l=0, r=height.size()-1;
            int area=0;
    
            while(l<r){
                int lenght = min(height[l], height[r]);
                int breadth = r-l;
                area = max(area, lenght*breadth);
    
                if(height[l] > height[r]){
                    r--;
                }
                else{
                    l++;
                }
            }
    
            return area;
        }
    };