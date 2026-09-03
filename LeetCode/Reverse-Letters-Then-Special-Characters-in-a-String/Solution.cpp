1class Solution {
2public:
3    string reverseByType(string s) {
4        string a, b;
5
6        for (char c : s) {
7            if (isalpha(c)) {
8                a.push_back(c);
9            } else {
10                b.push_back(c);
11            }
12        }
13
14        int j = a.size(), k = b.size();
15        for (int i = 0; i < s.size(); ++i) {
16            if (isalpha(s[i])) {
17                s[i] = a[--j];
18            } else {
19                s[i] = b[--k];
20            }
21        }
22
23        return s;
24    }
25};