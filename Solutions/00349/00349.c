/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,
                  int* returnSize) {
    if (nums2Size > nums1Size)
        return intersection(nums2, nums2Size, nums1, nums1Size, returnSize);

    int cnt = 0;

    int* ret = (int*)malloc(nums2Size * sizeof(int));
    int* hash1 = (int*)calloc(1001, sizeof(int));
    int* hash2 = (int*)calloc(1001, sizeof(int));

    for (size_t i = 0; i < nums1Size; ++i)
        hash1[nums1[i]]++;

    for (size_t i = 0; i < nums2Size; ++i)
        hash2[nums2[i]]++;

    for (size_t i = 0; i < 1001; ++i) {
        if (hash1[i] && hash2[i])
            ret[cnt++] = i;
    }

    *returnSize = cnt;

    free(hash1);
    free(hash2);

    return ret;
}