class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                nums[i] = -9999;
                count++;
            }
        }
        int index = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != -9999) {
                nums[index++] = nums[i];
            }
        }
        return size - count;
    }
};
