//leetcode: https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-09-29

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank;
                rank++;
            }
        }
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        return result;
    }
};
