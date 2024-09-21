//leetcode: https://leetcode.com/problems/shortest-palindrome/?envType=daily-question&envId=2024-09-20

class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0;
        int j =  s.size() - 1; 
        while (j >= 0) {
            if (s[i] == s[j]) {
                i++;
            }
            j--;
        }
        string remain = s.substr(i); 
        if( remain.size()==0 ){ return s; }
        string rev_remain = remain;
        reverse(rev_remain.begin(), rev_remain.end());
        return rev_remain + shortestPalindrome(s.substr(0, i)) + remain;
    }
};
/*The function finds the longest palindromic prefix by comparing characters from the start and end of the string.
It then reverses the remaining suffix and recursively adds it to both sides to form the shortest palindrome. */