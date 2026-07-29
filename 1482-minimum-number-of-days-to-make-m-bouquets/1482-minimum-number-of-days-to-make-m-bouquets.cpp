class Solution {
public:

bool check(int mid,vector<int>&v,int k,int m){
    int b=0;
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i]<=mid){
            cnt++;
            if(cnt>=k){
                b++;
                cnt=0;
            }
        }else{
            cnt=0;
        }
    }
    return b>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,bloomDay,k,m)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};