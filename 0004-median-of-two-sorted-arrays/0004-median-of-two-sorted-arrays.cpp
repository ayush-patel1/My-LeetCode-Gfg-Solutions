class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(nums1[i++]);
        }
        while(j<m){
            v.push_back(nums2[j++]);
        }
        int sz=v.size();
        if(sz%2==0){
            double ans=(v[sz/2]+v[sz/2-1])*1.0/2;
            return ans;
        }
        return v[sz/2];
    }
};