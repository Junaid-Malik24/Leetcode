//leetcode: https://leetcode.com/problems/different-ways-to-add-parentheses/submissions/1395588093/?envType=daily-question&envId=2024-09-19

/*Approach: At each operator,call the function recursively for the the expression on the right 
and expression on the left and then give the answers by equating the expression on the left and 
on the right while going throught the main expression until it comes down to single digits and operators
which get solved through the conditional statements and pushed in the result vector...the last condition checks
if an expression has no operators...in that case push the number into vector and return it
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*') {
                vector<int> leftResults =
                    diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults =
                    diffWaysToCompute(expression.substr(i + 1));
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (expression[i] == '+') {
                            results.push_back(left + right);
                        } else if (expression[i] == '-') {
                            results.push_back(left - right);
                        } else if (expression[i] == '*') {
                            results.push_back(left * right);
                        }
                    }
                }
            }
        }
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        return results;
    }
};
