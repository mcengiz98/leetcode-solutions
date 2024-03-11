int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* nums1_e = nums1 + nums1Size;
    int* nums2_e = nums2 + nums2Size;

    while (nums1 < nums1_e && nums2 < nums2_e) {
        if (*nums1 == *nums2)
            return *nums1;
        else if (*nums1 > *nums2)
            nums2++;
        else
            nums1++;
    }

    return -1;
}