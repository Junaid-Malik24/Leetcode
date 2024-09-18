//leetcode: https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18

//Approach 1 (Using Selection Sort with Conditioned Changed)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(to_string(nums[i]));
        }
        for (int i = 0; i < result.size() - 1; i++) {
            int mini = i;
            for (int j = i + 1; j < result.size(); j++) {
                if (result[j] + result[mini] > result[mini] + result[j]) {
                    mini = j;
                }
            }
            swap(result[i], result[mini]);
        }
        if (result[0] == "0") return "0";
        string resultt = "";
        for(int i = 0; i < result.size(); i++) {
            resultt += result[i];
        }

        return resultt;
    }
};

//Approach 2 (Using built-in sort function and passing a comparator condition along with it)
class Solution {
public:
    static bool comparator(int a, int b)
    {
        string s1 = to_string(a), s2 = to_string(b);
        return (s1 + s2) > (s2 + s1);
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), comparator);
        if (nums[0] == 0) return "0";
        string resultt = "";
        for(int i = 0; i < nums.size(); i++) {
            resultt += to_string(nums[i]);
        }

        return resultt;
    }
};