class Solution {
public:
bool check(int k,vector<int>&piles,int h){
    int need=0;
    for(auto &pile:piles){
        need+=(pile+k-1)/k;
        if(need>h) return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;  // changed
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,piles,h)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};