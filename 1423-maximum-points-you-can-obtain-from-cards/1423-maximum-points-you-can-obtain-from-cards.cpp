class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //find the minimum_subarray sum as this will be either 
        //somewhere in the middle it means the card is taken from both left and right
        //else it will be fully ending on right or left
        // we can find minimum subarray sum and subtract it from tot_sum to get max
        int n=cardPoints.size();
        int l=0,r=0;
        int len=n-k,tot_sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int min_sum=tot_sum;
        int curr_sum=0;
        while(r<n){
            curr_sum+=cardPoints[r];
            while(l<=r && r-l+1>len){
                curr_sum-=cardPoints[l];
                l++;
            }
            if(r-l+1==len) min_sum=min(min_sum,curr_sum);
            r++;
        }
        return tot_sum-min_sum;
    }
};