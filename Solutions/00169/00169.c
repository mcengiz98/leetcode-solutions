#include <stdlib.h>

int icmp(const void* vp1, const void* vp2) {
    return *(const int*)vp1 - *(const int*)vp2;
}

int majorityElement(int* nums, int numsSize) {
    if (numsSize == 1) {
        return *nums;
    }

    qsort(nums, numsSize, sizeof(int), icmp);

    int cnt = 1;
    int test = *nums;

    for (size_t i = 1; i < numsSize; ++i) {
        if (test == nums[i]) {
            cnt++;
        } else {
            if (cnt > (numsSize / 2)) {
                return test;
            }
            test = nums[i];
            cnt = 1;
        }
    }

    if (cnt > (numsSize / 2)) {
        return test;
    }

    return 0;
}