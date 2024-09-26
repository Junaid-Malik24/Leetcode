//leetcode: https://leetcode.com/problems/my-calendar-i/?envType=daily-question&envId=2024-09-26

//Approach 1 (Using vector pairs)
class MyCalendar {
public:
    vector<pair<int, int>> ranges;
    MyCalendar() {}
    bool book(int start, int end) {
        for (auto pair : ranges) {
            int r_start = pair.first;
            int r_end = pair.second;
            if (start < r_end && end > r_start)
            return false;
        }
        ranges.push_back(make_pair(start, end));
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

//Approach 2 (Using mapping)
class MyCalendar {
    map<int, int> events;
public:
    bool book(int start, int end) {
        auto next = events.lower_bound(start);
        if (next != events.end() && next->first < end) return false;
        if (next != events.begin() && prev(next)->second > start) return false;
        events[start] = end;
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */