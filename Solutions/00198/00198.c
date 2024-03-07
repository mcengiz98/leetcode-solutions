#define MAX(a,b) (((a) >(b))? (a) : (b))

int rob(int* nums, int numsSize) {
    int sum = 0;

    switch(numsSize){
        case 1:
            return nums[0];
        case 2:
            return MAX(nums[0],nums[1]);
        case 3:
            return MAX(nums[0] + nums[2], nums[1]);
    }
    nums[2] += nums[0];
    for (size_t i=3; i < numsSize; ++i)
        nums[i] += MAX(nums[i-2] , nums[i-3]);
    return MAX(nums[numsSize-1] , nums[numsSize-2]);

}