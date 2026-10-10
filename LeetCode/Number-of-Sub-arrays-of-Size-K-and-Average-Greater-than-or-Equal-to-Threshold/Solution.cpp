1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        threshold *= k;
5        int s = accumulate(arr.begin(), arr.begin() + k, 0);
6        int ans = s >= threshold;
7        for (int i = k; i < arr.size(); ++i) {
8            s += arr[i] - arr[i - k];
9            ans += s >= threshold;
10        }
11        return ans;
12    }
13};