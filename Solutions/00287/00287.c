int findDuplicate(int* nums, int numsSize) {
    int* mapaHash = (int*)calloc(numsSize, sizeof(int));
    for (size_t i = 0; i < numsSize; ++i) {
        if (mapaHash[nums[i]]) {
            free(mapaHash);
            return nums[i];
        } else {
            mapaHash[nums[i]]++;
        }
    }
    free(mapaHash);
    return -1;
}
