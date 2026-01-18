class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        stack<char> st;
        int n=s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<n;i++){     
            while(!st.empty() && s[i]<st.top() && freq[st.top()-'a']>1){
                freq[st.top()-'a']--;
                st.pop();
            }
            st.push(s[i]);
        }

        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        int i=(int)ans.size()-1;       
        while(i>=0 && freq[ans[i]-'a']>1){    
            freq[ans[i]-'a']--;
            ans.pop_back();
            i--;
        }

        return ans;
    }
};