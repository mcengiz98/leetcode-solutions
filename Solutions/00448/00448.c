/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* mapaHash = (int*)calloc(numsSize + 1, sizeof(int));
    int* ret = (int*)calloc(numsSize, sizeof(int));
    int cnt = 0;

    for (size_t i = 0; i < numsSize; ++i)
        mapaHash[nums[i]]++;
    for (size_t i = 1; i < numsSize + 1; ++i) {
        if (!mapaHash[i]) {
            ret[cnt++] = i;
        }
    }

    *returnSize = cnt;

    free(mapaHash);
    return ret;
}