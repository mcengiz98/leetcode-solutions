int icmp(const void* vp1, const void* vp2) {
    return *(const int*)vp1 - *(const int*)vp2;
}

int firstMissingPositive(int* nums, int numsSize) {
    for (size_t i = 0; i < numsSize;
         ++i) { // f*ck less than zero. all my hommies use positive integers
        if (nums[i] < 0)
            nums[i] = 0;
    }
    qsort(nums, numsSize, sizeof(int), icmp);
    int ret = 1;
    for (size_t i = 0; i < numsSize; ++i) {
        if (!nums[i])
            continue;
        if (nums[i] > ret)
            return ret;
        else {
            if (i + 1 == numsSize) {
                ret++;
                break;
            }
            if (nums[i] != nums[i + 1])
                ret++;
        }
    }

    return ret;
}