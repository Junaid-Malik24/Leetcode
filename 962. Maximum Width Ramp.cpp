//leetcode : https://leetcode.com/problems/maximum-width-ramp/?envType=daily-question&envId=2024-10-10

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                if(result<j-st.top())
                result=j-st.top();
                st.pop();
            }
        }
        return result;
    }
};
