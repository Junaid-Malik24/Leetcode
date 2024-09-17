//leetcode: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=daily-question&envId=2024-09-17

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> words; 
        vector<string> result;
        string word = "";
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != ' ') {
                word += s1[i];
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) {  
            words.push_back(word);
        }
        word = "";
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] != ' ') {
                word += s2[i];
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (!word.empty()) {  
            words.push_back(word);
        }
        for (string w : words) {
            int count = 0;
            for (string x : words) {
                if (w == x) {
                    count++;
                }
            }
            if (count == 1) {  
                result.push_back(w);
            }
        }
        return result;
    }
};
