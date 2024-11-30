//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minSteps(int n) 
	{ 

    vector<int> dp(n + 1, 0);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        if (i % 2 == 0) op1 = 1 + dp[i / 2];
        if (i % 3 == 0) op2 = 1 + dp[i / 3];
        op3 = 1 + dp[i - 1];
        dp[i] = min({op1, op2, op3});
    }

    return dp[n]; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends