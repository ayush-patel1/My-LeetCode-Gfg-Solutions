class Solution {
public:
    int countKthRoots(int l, int r, int k) {

        if(k==1){
            return r-l+1;
        }

        int x=0;

        while(true){

            long long val=pow(x,k);

            if(val>=l){
                break;
            }

            x++;
        }

        int ans=0;

        while(true){

            long long val=pow(x,k);

            if(val>r){
                break;
            }

            ans++;

            x++;
        }

        return ans;
    }
};