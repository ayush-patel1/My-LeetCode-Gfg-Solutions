class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n=nums.size();
        vector<int> visited(n,0);
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(nums[node]==0) return true;
            if(!visited[node]){
                visited[node]=1;
                if(nums[node]+node<n)
                    st.push(nums[node]+node);
                if(node-nums[node]>=0)
                    st.push(node-nums[node]);
            }
        }
        return false;
    }
};