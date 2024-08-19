//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        long long total_sum=accumulate(arr,arr+num,0);
        long long curr=0;
        long long minSum=1e18;
        for(int i=0;i<num;i++){
            curr+=arr[i];
            minSum=min(curr,minSum);
            if(curr>0){
                curr=0;
            }
        }
        
        long long maxSum=-1e18;
        curr=0;
        for(int i=0;i<num;i++){
            curr+=arr[i];
            maxSum=max(curr,maxSum);
            if(curr<0){
                curr=0;
            }
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(total_sum-minSum,maxSum);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends