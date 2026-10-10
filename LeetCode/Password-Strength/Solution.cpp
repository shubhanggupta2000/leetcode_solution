1class Solution {
2public:
3    int passwordStrength(string password) {
4        unordered_set<char> st(password.begin(), password.end());
5
6        int ans = 0;
7
8        for (char ch : st) {
9            if (islower(ch)) {
10                ans += 1;
11            } else if (isupper(ch)) {
12                ans += 2;
13            } else if (isdigit(ch)) {
14                ans += 3;
15            } else {
16                ans += 5;
17            }
18        }
19
20        return ans;
21    }
22};