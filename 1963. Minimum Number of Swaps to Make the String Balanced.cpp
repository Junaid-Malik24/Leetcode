//leetcode : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/?envType=daily-question&envId=2024-10-08

//Approach 1 (Without Using Stack)
class Solution {
public:
    int minSwaps(string s) {
        float result=0;
        for(int i=0;i<s.size();i++){
            if(result==0 && s[i]==']'){
                result+=0;
            }else if(s[i]==']'){
                result--;
            }else if(s[i]=='['){
                result++;
            }else{

            }
        }
        return ceil(result/2);
    }
};

//Approach 2 (Using Stack)
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ']' && st.empty()) {
                continue;
            }
            else if(s[i] == ']' && st.top() == '[') {
                st.pop();
            }
            else {
                st.push('[');
            }
        }
        return (st.size() + 1) / 2;
    }
};