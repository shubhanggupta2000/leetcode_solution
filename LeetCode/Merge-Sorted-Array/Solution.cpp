1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        for (int i = m - 1, j = n - 1, k = m + n - 1; ~j; --k) {
5            nums1[k] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
6        }
7    }
8};