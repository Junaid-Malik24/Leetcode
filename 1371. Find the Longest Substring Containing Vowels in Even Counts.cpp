//leetcode: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

//Approach 1(Seperate Function for bit Masking)
class Solution {
public:
    void updateBitmask(char ch, int& mask) {
        switch (ch) {
        case 'a':
            mask ^= (1 << 0);
            break;
        case 'e':
            mask ^= (1 << 1);
            break;
        case 'i':
            mask ^= (1 << 2);
            break;
        case 'o':
            mask ^= (1 << 3);
            break;
        case 'u':
            mask ^= (1 << 4);
            break;
        }
    }
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> firstOccurrence;
        int mask = 0;
        int maxLength = 0;
        firstOccurrence[0] = -1;
        for (int i = 0; i < s.size(); ++i) {
            updateBitmask(s[i], mask);
            if (firstOccurrence.find(mask) != firstOccurrence.end()) {
                maxLength = max(maxLength, i - firstOccurrence[mask]);
            } else {

                firstOccurrence[mask] = i;
            }
        }

        return maxLength;
    }
};

//Approach 2
class Solution {
public:

    int findTheLongestSubstring(string s) {
        unordered_map<int, int> firstOccurrence;
    int state = 0; 
    int maxLength = 0;
    firstOccurrence[0] = -1; 
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') state ^= (1 << 0);
        if (s[i] == 'e') state ^= (1 << 1);
        if (s[i] == 'i') state ^= (1 << 2);
        if (s[i] == 'o') state ^= (1 << 3);
        if (s[i] == 'u') state ^= (1 << 4);
        if (firstOccurrence.find(state) != firstOccurrence.end()) {
            maxLength = max(maxLength, i - firstOccurrence[state]);
        } else {
            firstOccurrence[state] = i;
        }
    }
    return maxLength;
    }
};

//Had to learn maps and bit masking for this so took a little help from gfg