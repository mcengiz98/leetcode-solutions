int uniquePaths(int m, int n)
{
    int DP[m + 1][n + 1];
    for (size_t i = 1; i <= m; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            if (i == 1 || j == 1)
            {
                DP[i][j] = 1;
                continue;
            }
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }

    return DP[m][n];
}