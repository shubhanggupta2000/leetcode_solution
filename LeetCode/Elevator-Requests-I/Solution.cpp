1class Solution {
2public:
3    int elevatorRequests(int n, vector<int>& requests) {
4        int ans = requests[0];
5        for (int i = 1; i < requests.size(); ++i) {
6            ans += abs(requests[i - 1] - requests[i]);
7        }
8        return ans;
9    }
10};