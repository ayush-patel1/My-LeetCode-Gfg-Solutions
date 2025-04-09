//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        unordered_map<int,int>mp;
        int curr_sum=0; int max_len=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            curr_sum+=arr[i];
            if(curr_sum==0) max_len=max(max_len,i+1);
            if(mp.find(curr_sum)!=mp.end()){
                max_len=max(max_len,i-mp[curr_sum]);
            }
            else{
                mp[curr_sum]=i;
            }
        }
        return max_len;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends