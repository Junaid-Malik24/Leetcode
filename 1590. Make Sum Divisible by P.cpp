//leetcode: https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2024-09-29

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        long long target = totalSum % p;
        if (target == 0) return 0;
        unordered_map<long long, int> prefixMap;
        prefixMap[0] = -1;
        long long currentSum = 0;
        int minLength = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            long long currentMod = currentSum % p;
            long long neededMod = (currentMod - target + p) % p;
            if (prefixMap.find(neededMod) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[neededMod]);
            }
            prefixMap[currentMod] = i;
        }
        return (minLength == nums.size()) ? -1 : minLength;
    }
};
