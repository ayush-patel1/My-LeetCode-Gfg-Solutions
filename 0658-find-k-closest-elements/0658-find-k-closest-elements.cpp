class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            int close=abs(arr[i]-x);
            int elem=arr[i];
            v[i]={close,elem};
        }
        sort(v.begin(),v.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        });
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].second);
        }
        sort(res.begin(),res.end());
        return res;
    }
};