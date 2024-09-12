//leetcode: https://leetcode.com/problems/valid-parentheses/

//Approach 1 (The simple One)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stackk;
        for (int i = 0; i < s.size(); i++) {
            if (stackk.empty()) {
                stackk.push(s[i]);
            } else {
                if(stackk.top()=='(' && (s[i]=='[' || s[i]=='{' || s[i]=='(')){
                  stackk.push(s[i]);
                }else if(stackk.top()=='{' && (s[i]=='[' || s[i]=='{' || s[i]=='(')){
                  stackk.push(s[i]);
                }
                else if(stackk.top()=='[' && (s[i]=='[' || s[i]=='{' || s[i]=='(')){
                  stackk.push(s[i]);
                }
                else if(stackk.top()=='(' && (s[i]=='}' || s[i]==']')){
                    return false;
                }else if(stackk.top()=='{' && (s[i]==')' || s[i]==']')){
                    return false;
                }else if(stackk.top()=='[' && (s[i]=='}' || s[i]==')')){
                    return false;
                }else if(stackk.top()==')' ||stackk.top()=='}'||stackk.top()==']'){
                    return false;
                }
                else{
                    stackk.pop();
                }
            }
        }
        if(!stackk.empty()){
            return false;
        }
        return true;
    }
};

//Approach 2 (Also the simple one)
class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> st;
        for (char c : s)
        { // For loop that processes the whole string character by character
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;
                if ((c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') || (c == ']' && st.top() != '['))
                {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};