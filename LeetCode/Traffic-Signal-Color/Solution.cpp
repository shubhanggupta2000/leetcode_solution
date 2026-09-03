1class Solution {
2public:
3    string trafficSignal(int timer) {
4        if (timer == 0) {
5            return "Green";
6        }
7        if (timer == 30) {
8            return "Orange";
9        }
10        if (timer > 30 && timer <= 90) {
11            return "Red";
12        }
13        return "Invalid";
14    }
15};