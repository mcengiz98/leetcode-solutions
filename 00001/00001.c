// This is not a good solution, but I don't want to writing a decent solution.

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * ret = (int*)malloc((2 * sizeof(int)));
    *returnSize = 2;
    int sum = 0;
    for (size_t i = 0; i < numsSize; ++i) {
        for (size_t j = i + 1; j < numsSize; ++j) {
            sum = nums[i] + nums[j];
            if (sum == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}