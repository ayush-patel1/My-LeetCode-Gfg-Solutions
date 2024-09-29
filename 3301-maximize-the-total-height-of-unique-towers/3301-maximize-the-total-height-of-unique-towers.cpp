class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        // unordered_map<int,int>mp;
        // int n=maximumHeight.size();
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     int height=maximumHeight[i];
        //     if(mp.find(height)==mp.end()){
        //         sum+=height;
        //     }
        //     else{
        //         while(mp.find(height)!=mp.end() && height>0){
        //             height--;
        //         }
        //         if(height<=0) return -1;
        //         else sum+=height;
        //     }
        //     mp[height]++;
        // }
        // return sum;
        
        int n=maximumHeight.size();
         sort(maximumHeight.begin(),maximumHeight.end());
        long long sum=0;
        int  curr=maximumHeight[n-1];
        
        for(int i=n-1;i>=0;i--){
            curr=min(curr,maximumHeight[i]);
            if(curr<=0) return -1;
            sum+=curr;
            curr--;
        }
         return sum;
    }
};