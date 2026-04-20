class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int mx=-1e9;
        for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
            if(colors[i]!=colors[j]){
                mx=max(mx,j-i);
            }
          }
        }
        return mx;
    }
};