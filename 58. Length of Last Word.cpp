//leetcode: https://leetcode.com/problems/length-of-last-word/

//Approach 1 (The O(n^2) solution) 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                result = 0; 
                for (int j = i; j < n && s[j] != ' '; j++) {
                    result++;  
                }
                while (i < n && s[i] != ' ') {
                    i++;
                }
            }
        }
        
        return result;
    }
};


//Approach 2 (The O(n) solution)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                continue;
            }else{
                while(i>=0 && s[i]!=' '){
                      result++;
                      i--;
                }
                break;
            }
        }
        return result;
    }
};