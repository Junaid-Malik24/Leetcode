leetcode: https://leetcode.com/problems/my-calendar-ii/?envType=daily-question&envId=2024-09-27

class MyCalendarTwo {
public:
    vector<pair<int, int>> ranges;
    vector<pair<int,int>> double_booked;
    MyCalendarTwo() {
    }
    bool book(int start, int end) {
        for (auto  pairr : double_booked) {
            int r_startt = pairr.first;
            int r_endd = pairr.second;
            if (start < r_endd && end > r_startt)
                return false;
        }
        for (auto  pair : ranges) {
            int r_start = pair.first;
            int r_end = pair.second;
            if (start < r_end && end > r_start)
                double_booked.push_back(make_pair(max(start, r_start), min(end, r_end)));
        }
        ranges.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */