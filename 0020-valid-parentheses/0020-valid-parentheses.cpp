class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &ch:s){
            if(st.empty()) st.push(ch);
            else{
                if(ch=='(' || ch=='{' || ch=='['){
                    st.push(ch);
                }else{
                    char t=st.top();
                    if(t=='(' && ch==')') st.pop();
                    else if(t=='{' && ch=='}') st.pop();
                    else if(t=='[' && ch==']') st.pop();
                    else return false;
                }
            }
        }
        return st.empty();
    }
};