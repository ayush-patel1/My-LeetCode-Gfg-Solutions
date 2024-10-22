//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    
    void solve(vector<int> arr,vector<vector<int>> &ans,vector<int> ds, int target,int index)
    {
        if(index ==arr.size())
        {
            if(target ==0)
            {
                
                ans.push_back(ds);
                
            }
            return;
        }
        
        // include
        if(arr[index]<=target && arr[index] != arr[index-1])
       {
           ds.push_back(arr[index]);
           solve(arr,ans,ds,target-arr[index],index);
           ds.pop_back();
        
        }        
        
        solve(arr,ans,ds,target,index+1);
       
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
       vector<vector<int>> ans;
       vector<int> ds;
       int index = 0;
       solve(A,ans,ds,B,index);
       return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends