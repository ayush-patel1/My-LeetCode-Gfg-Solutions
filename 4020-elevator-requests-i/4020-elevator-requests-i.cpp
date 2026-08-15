class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m=requests.size();
        int ans=0;
        for(int i=1;i<m;i++){
            ans+=abs(requests[i-1]-requests[i]);
        }
        ans+=abs(requests[0]);
        return ans;
    }
};