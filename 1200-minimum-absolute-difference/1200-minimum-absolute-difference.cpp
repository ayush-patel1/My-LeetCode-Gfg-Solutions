class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int min_diff = 1e9;
        for(int i = 0; i + 1 < n; i++){
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> ans;
        for(int i = 0; i + 1 < n; i++){
            if(arr[i + 1] - arr[i] == min_diff){
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};
