class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>vis(101,0);
        for(auto &b:bulbs){
            vis[b]=(vis[b]==0)?1:0;
        }
        vector<int>ans;
        for(int i=1;i<=100;i++){
            if(vis[i]) ans.push_back(i);
        }
        return ans;
    }
};