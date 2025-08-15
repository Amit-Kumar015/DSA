// https://neetcode.io/problems/meeting-schedule-ii?list=neetcode250

// sweep line algo
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for(auto& i: intervals){
            mp[i.start]++;
            mp[i.end]--;
        }

        int prev = 0, res = 0;
        for(auto& [key, value]: mp){
            prev += value;
            res = max(res, prev);
        }

        return res;
    }
};


// two pointers
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        for(auto& i: intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0, e = 0, cnt = 0, res = 0;
        while(s < intervals.size()){
            if(start[s] < end[e]){
                cnt++;
                s++;
            }
            else{
                cnt--;
                e++;
            }
            res = max(res, cnt);
        }

        return res;
    }
};


// min heap
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){
            return x.start < y.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& interval: intervals){
            if(!minHeap.empty() && minHeap.top() <= interval.start){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }

        return minHeap.size();
    }
};
