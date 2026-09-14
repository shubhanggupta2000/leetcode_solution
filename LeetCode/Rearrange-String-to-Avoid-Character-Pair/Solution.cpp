1class Solution {
2public:
3    string rearrangeString(string s, char x, char y) {
4        int i = 0;
5        for (int j = 0; j < s.size(); j++) {
6            if (s[j] == y) {
7                swap(s[i], s[j]);
8                i++;
9            }
10        }
11        return s;
12    }
13};