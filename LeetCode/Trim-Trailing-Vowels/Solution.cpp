1class Solution {
2public:
3    string trimTrailingVowels(string s) {
4        int i = s.size() - 1;
5        while (i >= 0 && string("aeiou").find(s[i]) != string::npos) {
6            i--;
7        }
8        return s.substr(0, i + 1);
9    }
10};