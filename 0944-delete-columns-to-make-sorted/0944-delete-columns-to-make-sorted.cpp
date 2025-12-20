class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       int n=strs.size(),m=strs[0].size();
       int cnt=0;
       for(int i=0;i<m;i++){
         bool flag=true;
         for(int j=0;j<n-1;j++){
            if(strs[j][i]>strs[j+1][i]){
                flag=false;
                break;
            }
         }
         if(!flag)  cnt++;
       }
       return cnt;
    }
};