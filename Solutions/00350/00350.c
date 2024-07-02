/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size,
               int* returnSize) {

    if (!nums1Size || !nums2Size) {
        *returnSize = 0;
        return NULL;
    }

    if (nums1Size < nums2Size)
        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);

    int* ret = (int*)malloc(nums1Size * sizeof(int));
    size_t cnt = 0;
    int* mapaHash = (int*)calloc(1001, sizeof(int));

    for (size_t i = 0; i < nums1Size; ++i)
        mapaHash[nums1[i]]++;

    for (size_t i = 0; i < nums2Size; ++i) {
        if (mapaHash[nums2[i]]) {
            ret[cnt++] = nums2[i];
            mapaHash[nums2[i]]--;
        }
    }
    free(mapaHash);
    *returnSize = cnt;
    return ret;
}