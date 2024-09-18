//leetcode: https://leetcode.com/problems/plus-one/

//Approach 1(The short method)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
//Approach 2 (The long method)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] == 9 && i == 0) {
                digits[i] = 0; 
                digits.insert(digits.begin(), 1); 
            }
            else if (digits[i] != 9) {
                digits[i] += 1; 
                break;
            }
            else {
                digits[i] = 0;
                if (digits[i-1] != 9) { 
                    digits[i-1] += 1;
                    break;
                }
            }
        }
        return digits;
    }
};

