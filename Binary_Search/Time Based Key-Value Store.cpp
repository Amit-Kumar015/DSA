// https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> m;
    public:
        TimeMap() {}
        
        void set(string key, string value, int timestamp) {
            m[key].emplace_back(timestamp, value);
        }
        
        string get(string key, int timestamp) {
            vector<pair<int, string>> values = m[key];
            int l=0, r=values.size()-1;
            string res="";
    
            while(l<=r){
                int mid = l+(r-l)/2;
                if(values[mid].first <= timestamp){
                    res = values[mid].second;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
    
            return res;
        }
    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */