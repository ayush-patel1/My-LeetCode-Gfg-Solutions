class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>a,b;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                a.insert(nums[i]^nums[j]);
            }

        }
        for(int i=0;i<n;i++){
            for(auto x:a){
                b.insert(nums[i]^x);
            }

        }
        return b.size();
    }
};