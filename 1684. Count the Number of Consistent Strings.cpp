//leetcode: https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12

//Approach 1 (Take the alphabets+is_allowed and mark those alphabets '1' which are in string by comparison)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        class checked_alphabet {
        public:
            char alphabet;
            bool is_allowed;
            checked_alphabet(char a, bool check = false) {
                alphabet = a;
                is_allowed = check;
            }
        };
        checked_alphabet alphas[26] = {
            ('a'), ('b'), ('c'), ('d'), ('e'), ('f'), ('g'), ('h'), ('i'),
            ('j'), ('k'), ('l'), ('m'), ('n'), ('o'), ('p'), ('q'), ('r'),
            ('s'), ('t'), ('u'), ('v'), ('w'), ('x'), ('y'), ('z')};
        for (int i = 0; i < allowed.size(); i++) {
            for (int j = 0; j < 26; j++) {
                if (allowed[i] == alphas[j].alphabet) {
                    alphas[j].is_allowed = true;
                }
            }
        }
        string exp = "";
        while (!words.empty()) {
            exp = words.back();
            bool is_consistent = true;
            for (int i = 0; i < exp.size(); i++) {
                if (!is_consistent) {
                    break;
                }
                for (int j = 0; j < 26; j++) {
                    if (exp[i] == alphas[j].alphabet &&
                        alphas[j].is_allowed != true) {
                        is_consistent = false;
                    }
                }
            }
            if (is_consistent) {
                result++;
            }
            words.pop_back();
        }
        return result;
    }
};

//Approach 2 (Straight up take a bool vector and mark those alphabets '1' which are in string using ASCII difference)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> count(26, 0);
        for (char c : allowed)//Either do this or iterate through allowed[i] to allowed[allowed.size()-1]
        {
            count[c-'a'] = 1;
        }
        int ans = 0;
        for (string s : words)
        {
            bool ok = true;
            for (char ch : s)
            {
                if (count[ch-'a'] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
        return ans;
    }
};