class Solution {
public:
    string f(string a,string b){
        if(a.find(b)!=-1) return a;
        int n=a.size(), m=b.size();
        int mx=0;
        for(int k=1;k<=min(n,m);k++){
            if(a.substr(n-k)==b.substr(0,k)) mx=k;
        }
        return a + b.substr(mx);
    }
    
    string merge(vector<string>&v){
        string t=f(v[0],v[1]);
        t=f(t,v[2]);
        return t;
    }

    string minimumString(string a, string b, string c) {
        vector<string>v={a,b,c};
        sort(v.begin(),v.end());
        string ans=a+b+c;
        do{
            string s=merge(v);
            if(s.size()<ans.size() || (s.size()==ans.size() && s<ans)) ans=s;
        }while(next_permutation(v.begin(),v.end()));
        return ans;
    }
};
