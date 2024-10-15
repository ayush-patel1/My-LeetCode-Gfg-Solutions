class Solution {
public:
    long long minimumSteps(string s) {
        long long zero_count=0;
        long long swaps=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                swaps+=zero_count;
            }else{
                zero_count++;
            }      
        }
        return swaps;
    }
};