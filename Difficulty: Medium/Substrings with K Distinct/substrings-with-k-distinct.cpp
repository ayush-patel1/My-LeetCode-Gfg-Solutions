//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  int solve(string& s, int k){
              // code here.
        int n=s.size();
        int left=0;
        int right=0; int tot=0;
        unordered_map<char,int>mp;
        while(right<n){
            mp[s[right]]++;
            while(left<=right && mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
           
                tot+=right-left+1;
            
            right++;
        }
        return tot;
  }
    int countSubstr(string& s, int k) {
      return solve(s,k)-solve(s,k-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends