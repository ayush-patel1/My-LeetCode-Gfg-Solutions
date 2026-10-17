
class Solution {
public:
    bool check(vector<string>& a) {
        int n = a.size();

        for (int i = 2; i < n; i++) {
            int h1 =
                stoi(a[i - 2].substr(0, 2)) * 60 + stoi(a[i - 2].substr(3, 2));
            int h2 = stoi(a[i].substr(0, 2)) * 60 + stoi(a[i].substr(3, 2));

            if (h2 - h1 <= 60)
                return true;
        }

        return false;
    }
    vector<string> alertNames(vector<string>& keyName,
                              vector<string>& keyTime) {
        unordered_map<string, vector<string>> mp;
        int n = keyName.size();

        for (int i = 0; i < n; i++) {
            mp[keyName[i]].push_back(keyTime[i]);
        }

        vector<string> ans;

        for (auto& a : mp) {
            auto& t = a.second;
            sort(t.begin(), t.end());

            if (check(t))
                ans.push_back(a.first);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
