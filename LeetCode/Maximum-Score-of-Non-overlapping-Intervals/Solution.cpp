1struct T {
2  long weight;
3  vector<int> selected;
4};
5
6class Solution {
7 public:
8  vector<int> maximumWeight(vector<vector<int>>& input) {
9    vector<Interval> intervals;
10    for (int i = 0; i < input.size(); ++i)
11      intervals.emplace_back(input[i][0], input[i][1], input[i][2], i);
12    ranges::sort(intervals);
13    vector<vector<T>> memo(intervals.size(), vector<T>(5));
14    return dp(intervals, memo, 0, 4).selected;
15  }
16
17 private:
18  using Interval = tuple<int, int, int, int>;
19
20  T dp(const vector<Interval>& intervals, vector<vector<T>>& memo, int i,
21       int quota) {
22    if (i == intervals.size() || quota == 0)
23      return T();
24    if (memo[i][quota].weight > 0)
25      return memo[i][quota];
26
27    T skip = dp(intervals, memo, i + 1, quota);
28
29    auto [_, r, weight, originalIndex] = intervals[i];
30    const int j = findFirstGreater(intervals, i + 1, r);
31    T nextRes = dp(intervals, memo, j, quota - 1);
32
33    vector<int> newSelected = nextRes.selected;
34    newSelected.push_back(originalIndex);
35    ranges::sort(newSelected);
36    T pick(static_cast<long>(weight) + nextRes.weight, newSelected);
37    return memo[i][quota] =
38               (pick.weight > skip.weight ||
39                pick.weight == skip.weight && pick.selected < skip.selected)
40                   ? pick
41                   : skip;
42  }
43
44  // Binary searches the first interval that starts after `rightBoundary`.
45  int findFirstGreater(const vector<Interval>& intervals, int startFrom,
46                       int rightBoundary) {
47    int l = startFrom;
48    int r = intervals.size();
49    while (l < r) {
50      const int m = (l + r) / 2;
51      if (get<0>(intervals[m]) > rightBoundary)
52        r = m;
53      else
54        l = m + 1;
55    }
56    return l;
57  }
58};