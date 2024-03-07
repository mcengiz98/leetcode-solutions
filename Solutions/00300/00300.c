int lengthOfLIS(int* nums, int numsSize) {
    int* dp = (int*)calloc(numsSize, sizeof(int));
    dp[0] = 1;
    int ret = 1;
    for (size_t i = 0; i < numsSize; ++i) {
        dp[i] =1;
        for (size_t j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ret = ret < dp[i] ? dp[i] : ret;
    }

    free(dp);
    return ret;
}