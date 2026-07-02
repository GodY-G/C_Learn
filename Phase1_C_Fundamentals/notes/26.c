int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)return 0;//异常处理numssize == 1
    int slow = 0;
    for(int fast = 1;fast < numsSize;fast++){
      if(nums[fast] != nums[slow]){//只有在不相等的时候才需要移动slow指针
        slow++;
        nums[slow] = nums[fast];
      }
    }
    return slow + 1;//长度等于下标+1
}