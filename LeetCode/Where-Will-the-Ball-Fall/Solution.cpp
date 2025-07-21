    int[] dp = new int[m];
    for (int c = 0; c < m; c++) {
        dp[c] = c;
    }
    int nc;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (dp[c] == -1) {
                continue;
            }
            nc = dp[c] + grid[r][c];
            if (nc >= 0 && nc < m) {
                if (grid[r][c] == grid[r][nc]) {
                    dp[c] = nc;
                }
                else {
                    dp[c] = -1;
                }

            }
            else {
                dp[c] = -1;
            }
        }
    }
    return dp;