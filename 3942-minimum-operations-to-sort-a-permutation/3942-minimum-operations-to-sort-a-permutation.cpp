        //only 4 possible cases
        //increasing->0
        //descreasing->1
        //increasing then again increasing with last elem<first->1
        //decrasing  then again decreasing with first elem<last_elem then reverse->2
        //else -1
class Solution {
public:
    int cal(vector<int>&v){
        int n = v.size();

        int ans = 1e9;
        
        // increasing
        int cnt1 = 0;
        int ans1 = 1;
        for(int i = 1;i<n;i++){
            if(v[i]<v[i-1]) cnt1++;
            if(cnt1==0) ans1++;
        }
        if(cnt1==1 && v[0]>v[n-1]) ans = min(ans,ans1);
        else if(cnt1==0) ans = min(ans,0);

        // decreasing
        int cnt2 = 0;
        int ans2 = 1;
        for(int i = 1;i<n;i++){
            if(v[i]>v[i-1]) cnt2++;
            if(cnt2==0) ans2++;
        }
        if(cnt2==1 && v[0] < v[n-1]) ans = min(ans,ans2+1);
        else if(cnt2==0) ans = min(ans,1);

        return ans;
        
    }
    int minOperations(vector<int>& nums) {

        vector<int>v1 = nums;
        
        vector<int>v2 = nums;
        reverse(v2.begin(),v2.end());

        int ans = min(cal(v1),cal(v2)+1);
        if(ans==1e9) ans = -1;
        return ans;
    }
};