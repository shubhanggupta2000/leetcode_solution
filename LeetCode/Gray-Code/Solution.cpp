1class Solution {
2public:
3    vector<int> grayCode(int n) {
4        vector<int> ans;
5        for (int i = 0; i < 1 << n; ++i) {
6            ans.push_back(i ^ (i >> 1));
7        }
8        return ans;
9    }
10};