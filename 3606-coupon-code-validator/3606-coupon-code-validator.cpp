class Solution {
public:
    bool check(string &code) {
        if (code.empty()) return false;
        for (char c : code) {
            if (!(
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                (c == '_')
            )) return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> res;
        int n = code.size();

        unordered_map<string, vector<string>> buckets;

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (!check(code[i])) continue;

            string bl = businessLine[i];
            if (bl != "electronics" && bl != "grocery" && bl != "pharmacy" && bl != "restaurant") continue;

            buckets[bl].push_back(code[i]);
        }

        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};

        for (string bl : order) {
            vector<string> &v = buckets[bl];
            sort(v.begin(), v.end());
            for (string c : v) {
                res.push_back(c);
            }
        }

        return res;
    }
};
