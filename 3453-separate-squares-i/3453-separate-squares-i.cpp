class Solution {
public:
bool check(vector<vector<int>>& squares, double mid){
    double f=0,s=0;
    for(auto &it:squares){ 
        double y=it[1], l=it[2];

        if(y >= mid){
            s += l*l;
        }
        else if(y + l <= mid){
            f += l*l;
        }
        else{
            f += (mid - y) * l;
            s += (y + l - mid) * l;
        }
    }
    return f >= s;  
}


double separateSquares(vector<vector<int>>& squares) {
    double l=0,r=0;
    for(auto &it:squares){
        r=max(r,(double)it[1]+it[2]);   
    }

    double ans=r;
    while(r-l>1e-6){
        double mid=(l+r)/2;
        if(check(squares,mid)){
            ans=mid;
            r=mid;
        }else{
            l=mid;
        }
    }
    return ans;
}
};
