1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int l = 0;
5        int r = s.size() - 1;
6
7        while (l < r) {
8            swap(s[l++], s[r--]);
9        }
10    }
11};