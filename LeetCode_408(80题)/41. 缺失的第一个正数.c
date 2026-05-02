int firstMissingPositive(int* nums, int numsSize) {
    for(int i = 0;i < numsSize;++i){
        while(nums[i]>0&&nums[i]<=numsSize&&nums[nums[i] - 1] != nums[i]){
            int correctIdx = nums[i] - 1;
            int temp = nums[i];
            nums[i] = nums[correctIdx];
            nums[correctIdx] = temp;
        }
    }
    for(int i = 0;i < numsSize;++i){
        if(nums[i] != i +1){
            return i + 1;
        }
    }
    return numsSize + 1;
}