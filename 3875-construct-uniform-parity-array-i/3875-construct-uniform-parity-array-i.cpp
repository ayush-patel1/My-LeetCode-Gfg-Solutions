class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        // try even;
        int e = 0, o = 0;
        for (auto& n : nums1) {
            if (n & 1)
                o++;
            else
                e++;
        }
        if(e==n || o==n) return true;
        return true;
    }
};