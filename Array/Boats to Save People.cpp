// https://leetcode.com/problems/boats-to-save-people/description/

class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
    
            int s=0, e=people.size()-1;
            int count=0;
    
            while(s<=e){
                int remain = limit - people[e];
                e--;
                count++;
    
                if(s <= e && remain >= people[s]){
                    s++;
                }
            }
    
            return count;
        }
    };