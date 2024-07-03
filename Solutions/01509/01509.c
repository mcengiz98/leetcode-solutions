int icmp(const void* vp1, const void* vp2) {
    return *(const int*)vp1 - *(const int*)vp2;
}

int minDifference(int* nums, int numsSize) {
    if (numsSize <= 3)
        return 0;
    qsort(nums, numsSize, sizeof(int), &icmp);

    int ret = INT_MAX;

    for (size_t i = 0; i < 4; ++i) {
        int temp = nums[numsSize - 4 + i] - nums[i];
        ret = ret < temp ? ret : temp;
    }

    return ret;
}