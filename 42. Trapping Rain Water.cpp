//leetcode : https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int maxx = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            if (st.empty()) {
                maxx = height[i];
                st.push(height[i]);
            } 
            else if (height[i] >= maxx) {
                while (!st.empty() && st.top() != maxx) {
                    water += maxx - st.top();
                    st.pop();
                }
                st.pop();
                maxx = height[i];
                st.push(height[i]);
            } 
            else {
                st.push(height[i]);
            }
        }
        int right_max = 0;
        while (!st.empty()) {
            right_max = max(right_max, st.top());
            water += right_max - st.top();
            st.pop();
        }
        return water;
    }
};
