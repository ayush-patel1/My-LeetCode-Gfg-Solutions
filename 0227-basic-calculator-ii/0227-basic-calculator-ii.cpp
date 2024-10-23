class Solution {
public:
    int calculate(string s) {
       int num=0;
        int n=s.size();
        int curr_sign='+';  //first number ke phele koi sign nhi hota isliye postive
        stack<int>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            if(!isdigit(ch) && ch!=' '|| i==n-1){
                if(curr_sign=='+'){
                    st.push(num);     //agr plus ya minus ho to jo curr number formed h usko push kr do
                }
                if(curr_sign=='-'){
                    st.push(-num);
                }
                if(curr_sign=='*'){    //agr multiply ya divide aaye to operation perform kr do
                    int op1=st.top();
                    st.pop();
                    st.push(op1*num);
                }
                if(curr_sign=='/'){
                    int op1=st.top();
                    st.pop();
                    st.push(op1/num);
                }
                curr_sign=ch;
                num=0;
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};