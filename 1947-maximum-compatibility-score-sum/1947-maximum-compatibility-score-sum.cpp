#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int getSum(const vector<int>& student, const vector<int>& mentor) {
        int n = student.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (student[i] == mentor[i]) {
                sum++;
            }
        }
        return sum;
    }
    
   
    int solve(int index, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool>& used) {
        int n = students.size();
        
    
        if (index == n) {
            return 0;
        }
        
        int maxSum = 0;
        
       
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
               
                used[i] = true;
                
              
                int currentSum = getSum(students[index], mentors[i]) + solve(index + 1, students, mentors, used);
                
                // Update the maximum sum found
                maxSum = max(maxSum, currentSum);
                
                
                used[i] = false;
            }
        }
        
        return maxSum;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        vector<bool> used(n, false);
        
        
        return solve(0, students, mentors, used);
    }
};
