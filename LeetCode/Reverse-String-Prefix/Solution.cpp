1class Solution {
2public:
3    string reversePrefix(string s, int k) {
4        string t = s.substr(0, k);
5        reverse(t.begin(), t.end());
6        return t + s.substr(k);
7    }
8};