class Solution {
public:
unordered_set<int> st;

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int len=1;len<=50;len++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){

                    if(len==1){
                        st.insert(grid[i][j]);
                        continue;
                    }

                    int k=len-1;
                    if(i-k<0 || i+k>=n || j-k<0 || j+k>=m) continue;

                    int cnt=0,sum=0;
                    int r=i-k,c=j;

                    while(cnt<k){
                        sum+=grid[r][c];
                        r++; c--;
                        cnt++;
                    }

                    cnt=0;
                    while(cnt<k){
                        sum+=grid[r][c];
                        r++; c++;
                        cnt++;
                    }

                    cnt=0;
                    while(cnt<k){
                        sum+=grid[r][c];
                        r--; c++;
                        cnt++;
                    }

                    cnt=0;
                    while(cnt<k){
                        sum+=grid[r][c];
                        r--; c--;
                        cnt++;
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> v;
        for(auto &x:st) v.push_back(x);

        sort(v.rbegin(),v.rend());

        if(v.size()<=3) return v;

        return {v[0],v[1],v[2]};
    }
};