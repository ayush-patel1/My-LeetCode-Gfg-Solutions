typedef long long ll;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int n=sentence.size();
        vector<string> v;
        string s="";
        
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                v.push_back(s);
                s="";
            }else{
                s+=sentence[i];
            }
        }
        if(!s.empty()) v.push_back(s);

        for(int i=0;i<v.size();i++){
            if(!v[i].empty() && v[i][0]=='$'){
                string t=v[i].substr(1);
                bool ok=true;
                for(char c:t) if(!isdigit(c)) ok=false;

                if(ok && !t.empty()){
                    ll num=stoll(t);
                    ll val=num*(100-discount);

                    ll d=val/100;
                    ll c=val%100;

                    string p=to_string(d)+".";
                    if(c<10) p+="0";
                    p+=to_string(c);

                    v[i]="$"+p;
                }
            }
        }

        string ans="";
        for(int i=0;i<v.size();i++){
            if(i) ans+=" ";
            ans+=v[i];
        }
        return ans;
    }
};