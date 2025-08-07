// https://leetcode.com/problems/coupon-code-validator/description/

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        map<int, vector<string>> m;
        int n = code.size();
        for (int i = 0; i < n; i++) {
            string coupon = code[i];
            bool isCode = false, isBusinessLine = false;

            if (coupon.size() > 0) {
                for (int j = 0; j < coupon.size(); j++) {
                    if ((coupon[j] >= 48 && coupon[j] <= 57) ||
                        (coupon[j] >= 65 && coupon[j] <= 90) ||
                        (coupon[j] >= 97 && coupon[j] <= 122) ||
                        (coupon[j] == 95)
                    ) {
                        isCode = true;
                    } else {
                        isCode = false;
                        break;
                    }
                }
            }

            if (businessLine[i] == "electronics" ||
                businessLine[i] == "grocery" || businessLine[i] == "pharmacy" ||
                businessLine[i] == "restaurant") {
                isBusinessLine = true;
            }

            if (isCode && isBusinessLine && isActive[i]) {
                if(businessLine[i] == "electronics")
                    m[0].push_back(code[i]);
                else if(businessLine[i] == "grocery")
                    m[1].push_back(code[i]);
                else if(businessLine[i] == "pharmacy")
                    m[2].push_back(code[i]);
                else
                    m[3].push_back(code[i]);
            }
        }

        for (auto& c : m) {
            sort(c.second.begin(), c.second.end());
        }
        vector<string> ans;
        for(const auto& a: m){
            vector<string> tmp = a.second;
            for (string code : tmp) {
                ans.push_back(code);
            }
        }

        return ans;
    }
};