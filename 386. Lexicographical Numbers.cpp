//leetcode: https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21

//Approach 1 (Built in sort function and sorting while comparing numbers as strings)
class Solution {
public:
    static bool comparator(int a, int b) {
        string s1 = to_string(a), s2 = to_string(b);
        return s1 < s2;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            result.push_back(i);
        }
        sort(result.begin(), result.end(), comparator);
        return result;
    }
};

//Approach 2 (Just processes them as numbers but multiples of 10 of the numbers(i.e 1*10=10) are neighbours of the numbers(i.e 1))
class Solution{
public:
    vector<int> lexicalOrder(int n) {
        vector<int> vec;
        int curr = 1;
        for (int i = 0; i < n; i++) {
            vec.push_back(curr); 
            if (curr * 10 <= n) {
                curr *= 10;  
            } else {
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr /= 10;
                }
                curr++;  
            }
        }
        return vec;
    }
};