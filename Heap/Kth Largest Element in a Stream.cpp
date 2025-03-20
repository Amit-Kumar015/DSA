// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
    public:
        priority_queue<int, vector<int>, greater<int>> minH;
        int size;
    
        KthLargest(int k, vector<int>& nums) {
            size = k;
    
            for(int num: nums){
                minH.push(num);
                if(minH.size() > size){
                    minH.pop();
                }
            }
        }
        
        int add(int val) {
            minH.push(val);
    
            if(minH.size() > size){
                minH.pop();
            }
    
            return minH.top();
        }
    };
    
    /**
     * Your KthLargest object will be instantiated and called as such:
     * KthLargest* obj = new KthLargest(k, nums);
     * int param_1 = obj->add(val);
     */