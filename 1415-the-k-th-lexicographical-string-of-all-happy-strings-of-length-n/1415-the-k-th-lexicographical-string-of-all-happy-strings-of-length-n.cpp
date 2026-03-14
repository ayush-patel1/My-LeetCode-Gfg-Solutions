class Solution {
public:
int m;
void solve(int idx,string &s,unordered_set<string>&v){
    if(idx>=m){
        v.insert(s);
        return;
    }
    for(char ch='a';ch<='c';ch++){
        if(s.empty() || (!s.empty() && s.back()!=ch)){
            s.push_back(ch);
            solve(idx+1,s,v);
            s.pop_back();
        }
    }
}
    string getHappyString(int n, int k) {
        m=n;
        unordered_set<string>v;
        string s="";
        solve(0,s,v);
        vector<string>arr;
        for(auto &it:v) arr.push_back(it);
        sort(arr.begin(),arr.end());
        return arr.size()>=k?arr[k-1]:"";
    }
};