/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // sort
    for (int i=0; i < numsSize; i++){
        while (nums[i] != nums[nums[i]-1]){
            int temp = nums[nums[i]-1];  
            nums[nums[i]-1] = nums[i]; 
            nums[i] = temp; 
        }
    }


    for (size_t i = 0; i < numsSize; ++i) {
        if (i+1 != nums[i]) {
            ret[0] = nums[i];
            ret[1] = i+1;
        }
    }

    return ret;
}