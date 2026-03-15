class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();       
        map<int,int> m1,m2;

        for(auto &x:nums1) m1[x]++;
        for(auto &x:nums2) m2[x]++;

        int cost=0;

        for(auto &p:m1){
            int x=p.first;
            int tot=p.second + m2[x];
            if(tot%2) return -1;

            cost+=abs(m1[x]-m2[x])/2;
        }

        for(auto &p:m2){
            if(m1.count(p.first)) continue;
            if(p.second%2) return -1;
            cost+=p.second/2;
        }

        return cost/2;
    }
};