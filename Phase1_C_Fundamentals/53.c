int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 0)return 0;
    int cur = 0,max = nums[0];
    for(int i = 0;i < numsSize;++i){
       cur = (cur > 0 ? cur : 0) + nums[i];
       if(cur > max)max = cur;
    }
    return max;
}