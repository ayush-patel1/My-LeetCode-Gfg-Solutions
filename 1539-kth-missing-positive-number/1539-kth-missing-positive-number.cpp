class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>st(arr.begin(),arr.end());
        int missing=0;
        for(int i=1;i<=2000;i++){
            if(st.find(i)==st.end() && missing<k){
                missing++;
                if(k==missing){
                    return i;
                }
            }
        }
        return -1;
    }
};