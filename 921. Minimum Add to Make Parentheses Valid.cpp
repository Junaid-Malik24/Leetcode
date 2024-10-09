//leetcode : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/?envType=daily-question&envId=2024-10-09

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open++;
            else {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return open + close;
    }
};