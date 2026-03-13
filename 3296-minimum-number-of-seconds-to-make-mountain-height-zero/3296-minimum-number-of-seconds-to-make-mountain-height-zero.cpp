class Solution {
public:
#define ll long long

bool check(ll t,ll h,vector<int>&arr){
    ll tot=0;
    for(auto &w:arr){
        ll l=0,r=1e6,k=0;
        while(l<=r){
            ll mid=(l+r)/2;
            if((mid*(mid+1)/2)*w<=t){
                k=mid;
                l=mid+1;
            }else r=mid-1;
        }
        tot+=k;
    }
    return tot>=h;
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    ll l=1,r=(ll)mountainHeight*(*max_element(workerTimes.begin(),workerTimes.end()))*mountainHeight;
    ll ans=r;

    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid,mountainHeight,workerTimes)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return ans;
}
};