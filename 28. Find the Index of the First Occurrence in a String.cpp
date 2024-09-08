class Solution {
public:
    int strStr(string haystack, string needle) {
        int answer = 0;
        bool flag = false;
        if(haystack.size()<needle.size()){
            return -1;
        }
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                answer = i;
                flag = true;
                for (int j = 1; j < needle.size(); j++) {
                    if (i + j < haystack.size() &&
                        needle[j] != haystack[i + j]) {
                        answer = 0;
                        flag = false;
                    }
                }
                if (flag && answer+needle.size()<=haystack.size()) {
                    return answer;
                }
            }
        }
        return -1;
    }
};
/*
In this Solution:
We iterate over the `haystack'string,checking if the first character matches the start of `needle`string...
Once we find a match,we use a nested loop to compare the subsequent characters of both strings...
If any character does not match,we reset and continue the search...
If the match is successful,we return the starting index. Otherwise,if no match is found, we return -1...
*/