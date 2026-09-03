class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>e,o;
        for(auto &it:nums1){
            if(it&1) o.push_back(it);
            else e.push_back(it);
        }
        if(e.size()==n || o.size()==n) return true;
        //ab odd hi bna skte bs 
        sort(o.begin(),o.end());
        for(auto &it:nums1){
            if(it&1) continue;
            else{
                auto idx=lower_bound(o.begin(),o.end(),it);
                if(idx==o.begin()) return false;
            }
        }
        return true;
    } 
};