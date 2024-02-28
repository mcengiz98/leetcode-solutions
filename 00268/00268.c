int icmp(const void* vp1, const void* vp2){
    return *(const int*)vp1 - *(const int*)vp2;
}

int missingNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),&icmp);
    size_t i=0;
    for(; i < numsSize; ++i){
        if(i!=nums[i]){
            break;
        }
    }

    return i;
}