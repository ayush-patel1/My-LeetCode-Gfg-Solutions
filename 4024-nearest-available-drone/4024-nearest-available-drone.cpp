class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int min_idx=-1;
        int mn=1e9;
        int n=drones.size();
        for(int i=0;i<n;i++){
            auto it=drones[i];
            int d=abs(it[0]-target[0])+abs(it[1]-target[1]);
            if(d<mn && d<=it[2]){
                min_idx=i;
                mn=d;
            }
        }
        return min_idx;
    }
};