class Solution {
public:
    #define ll long long
    int mirrorDistance(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int r=stoi(s);
        return abs(n-r);
    }
};