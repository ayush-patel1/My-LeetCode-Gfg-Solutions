class Solution {
public:
    int vowelConsonantScore(string s) {
        vector<char> ch = {
            'b','c','d','f','g','h','j','k','l','m',
            'n','p','q','r','s','t','v','w','x','y','z'
        };

        unordered_set<char> c(ch.begin(), ch.end());
        unordered_set<char> v({'a','e','i','o','u'});

        int cc = 0, vc = 0;

        for (auto &x : s) {
            if (c.find(x) != c.end()) cc++;
            if (v.find(x) != v.end()) vc++;
        }

        if (cc > 0) return vc / cc;
        return 0;
    }
};
