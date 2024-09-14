//leetcode: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-14

//Approach 1(The one with more time complexity)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int max_val = *max_element(nums.begin(), nums.end()); 
        int max_count = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_val) {
                result++;
            } else {
                max_count = max(max_count, result);
                result = 0;
            }
        }
        max_count = max(max_count, result);
        return max_count;
    }
};

//Approach 1(The one with less time complexity)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int length = 0;
        int maxVal = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxVal) {
                count++;
                length = max(length, count);
            } else {
                count = 0;
            }
        }
        return length;
    }
};
