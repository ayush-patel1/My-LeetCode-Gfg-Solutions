class Solution {
public:
#define ll long long

vector<vector<ll>> v;
ll min_ans;

void pre_dp(){
    v.assign(51, vector<ll>(51,0));
    for(int i=0;i<=50;i++){
        v[i][0]=1;
        for(int j=1;j<=i;j++){
            v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
    }
}

void dfs(int idx,int ones,ll cur,ll &n){
    if(cur>=min_ans) return;
    if(idx<0){
        if(ones==0){
            n--;
            if(n==0) min_ans=min(min_ans,cur);
        }
        return;
    }
    if(ones>idx+1) return;

    ll cnt0 = (idx>=ones)?v[idx][ones]:0;
    if(cnt0>=n){
        dfs(idx-1,ones,cur,n);
    }else{
        n-=cnt0;
        dfs(idx-1,ones-1,cur|(1LL<<idx),n);
    }
}

long long nthSmallest(long long n,int k){
    pre_dp();
    int lim=-1;
    for(int i=k;i<=50;i++){
        if(v[i][k]>=n){
            lim=i;
            break;
        }
    }
    min_ans=LLONG_MAX;
    dfs(lim-1,k,0,n);
    return min_ans;
}
};
