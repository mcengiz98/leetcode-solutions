#include <stdlib.h>

int icmp(const void *vp1, const void *vp2)
{
    return *(const int *)vp1 - *(const int *)vp2;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1){
        return false;
    }

    qsort(nums, numsSize, sizeof(int), icmp);

    for(size_t i=0; i < numsSize-1; ++i){
        if (nums[i] == nums[i+1])
            return true;
    }


    return false;
}