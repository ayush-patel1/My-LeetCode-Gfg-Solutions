//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int>ans;
        long int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1])
             { 
                 sum=sum-arr[i];
               ans.push_back(arr[i]);
            }
        }
       long int csum=0;
        long int size=arr.size();
        csum=(size*(size+1))/2;
        int final_ans=csum-sum;
         ans.push_back(final_ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends