//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left=0,right=0;
        int max_len=0;
        unordered_map<int,int>st;
        while(right<n){
            st[arr[right]]++;
            while(left<=right && st.size()>2){
                st[arr[left]]--;
                if(st[arr[left]]==0){
                    st.erase(arr[left]);
                }
                left++;
            }
            max_len=max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends