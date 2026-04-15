class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int min_dis = 1e9;
        if (words[startIndex] == target)
            return 0;
        int s = (startIndex - 1 + n) % n;
        while (s != startIndex) {
            if (words[s] == target) {
                min_dis = min(min_dis, abs((startIndex - s + n) % n));
            }
            s = (s - 1 + n) % n;
        }
        s=startIndex+1;
        while (s != startIndex) {
            if (words[s] == target) {
                min_dis = min(min_dis, abs((s-startIndex + n) % n));
            }
            s = (s + 1 + n) % n;
        }
        return min_dis==1e9?-1:min_dis;
    }
};