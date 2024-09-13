//leetcode:https://leetcode.com/problems/xor-queries-of-a-subarray/?envType=daily-question&envId=2024-09-13

//Approach 1 (Brute Force)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        int start = 0;
        int end = 0;
        int XOR_result = 0;
        for (int i = 0; i < queries.size(); i++) {
            XOR_result = 0;
            start = queries[i][0];
            end = queries[i][1];
            for (int j = start; j <= end; j++) {
                XOR_result ^= arr[j];
            }
            result.push_back(XOR_result);
        }
        return result;
    }
};

//Approach 2 (A more optimized approach performing XOR in place)
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i - 1];
        }
        for (const vector<int>& q : queries) {//You can use const auto& as well
            if (q[0] > 0) {
                result.push_back(arr[q[0] - 1] ^ arr[q[1]]);
            } else {
                result.push_back(arr[q[1]]);
            }
        }
        return result;
    }
};
//Formula for above to solve in O(1)--> XOR from index L to R=prefix XOR at R⊕prefix XOR at (L−1)