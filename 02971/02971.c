int icmp(const void* vp1, const void* vp2) {
    return *(const int*)vp1 - *(const int*)vp2;
}

long long sum_arr(int* arr, int size) {
    long long sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += arr[i];
    return sum;
}

long long checkPoly(int* arr, int size) {
    if (size < 3)
        return -1;
    long long sum = sum_arr(arr, size - 1);
    if (sum > arr[size - 1])
        return (sum + arr[size - 1]);
    else
        return checkPoly(arr, size - 1); // drop largest element and control again
}

long long largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), &icmp);
    return checkPoly(nums, numsSize);
}