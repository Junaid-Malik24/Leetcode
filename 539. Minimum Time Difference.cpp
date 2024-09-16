//leetcode: https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        string hours = "";
        string mins = "";
        int hr = 0;
        int minute = 0;
        for (string exp : timePoints) {
            hours = exp.substr(0, 2);
            mins = exp.substr(3, 2);
            hr = stoi(hours) * 60;
            minute = stoi(mins);
            int totalMinutes = hr + minute;
            time.push_back(totalMinutes);
        }
        sort(time.begin(), time.end());
        time.push_back(time[0] + 1440);
        int min_diff = INT_MAX;
        for (int i = 1; i < time.size(); i++) {
            min_diff = min(min_diff, time[i] - time[i - 1]);
        }
        return min_diff;
    }
};
