1class Solution {
2public:
3    int secondsBetweenTimes(string startTime, string endTime) {
4        return f(endTime) - f(startTime);
5    }
6
7private:
8    int f(const string& s) {
9        return stoi(s.substr(0, 2)) * 3600
10            + stoi(s.substr(3, 2)) * 60
11            + stoi(s.substr(6));
12    }
13};