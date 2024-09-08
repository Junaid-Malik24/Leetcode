class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int> stackk;
        stack<int> stackk2;
        stackk.push(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != stackk.top()) {
                stackk.push(nums[i]);
            }
        }
        int count = 0;
        while (!stackk.empty()) {
            stackk2.push(stackk.top());
            stackk.pop();
        }
        while (!stackk2.empty()) {
            nums[count++] = stackk2.top();
            stackk2.pop();
        }
        return count;
    }
};
//As the reverse is sorted...so it must have equal elements adjacent to each other....hence stack can be used 
//Just for the sake of comparing with the next element and then put in another stack to reverse it 
//Then put the stack2 entries back into the array and maintain count throughout and then return it