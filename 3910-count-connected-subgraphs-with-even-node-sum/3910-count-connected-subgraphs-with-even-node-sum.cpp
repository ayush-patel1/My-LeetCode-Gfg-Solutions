class Solution {
public:
    int find(int x, vector<int>& p){
        if(p[x]==x) return x;
        return p[x]=find(p[x],p);
    }
    
    void unite(int a,int b, vector<int>& p){
        a=find(a,p);
        b=find(b,p);
        if(a!=b) p[a]=b;
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        int cnt=0;

        for(int i=1;i<(1<<n);i++){
            unordered_set<int> st;
            
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    st.insert(j);
                }
            }

            vector<int> p(n);
            for(int j=0;j<n;j++) p[j]=j;

            int cur_sum=0;
            for(auto x:st) cur_sum+=nums[x];

            for(auto &edge:edges){
                int u=edge[0], v=edge[1];
                if(st.count(u) && st.count(v)){
                    unite(u,v,p);
                }
            }

            int comp=0;
            for(auto x:st){
                if(find(x,p)==x) comp++;
            }

            if(comp==1 && cur_sum%2==0) cnt++;
        }
        return cnt;
    }
};