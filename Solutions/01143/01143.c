int longestCommonSubsequence(char *text1, char *text2)
{
    size_t t1_len = strlen(text1);
    size_t t2_len = strlen(text2);

    int DP[t1_len + 1][t2_len + 1];

    for (size_t i = 0; i <= t1_len; ++i)
    {
        for (size_t j = 0; j <= t2_len; ++j)
        {
            if (i == 0 || j == 0)
            {
                DP[i][j] = 0;
                continue;
            }
            if (text1[i - 1] == text2[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = fmax(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    return DP[t1_len][t2_len];
}