

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            
            if (c == '+' || c == '-' || c == '*') {
                 vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));
                
               
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        
       
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};


