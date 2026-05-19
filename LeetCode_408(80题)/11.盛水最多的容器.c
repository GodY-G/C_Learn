//暴力解法
int maxArea(int* height, int heightSize) {
    if(heightSize < 2)return 0;

    int temp = 0;
    int width = 0;
    int length = 0;
    int max = 0;
    for(int i = 0;i < heightSize;++i){
        int multiply = 0;
        for(int j = i + 1;j < heightSize;++j){
            if(i == heightSize - 1)break;
            width = j - i;
            length = (height[i] < height[j]) ? height[i] : height[j];
            multiply = width * length;
            if(multiply > max)max = multiply;
        }
    }
    return max;
}
//双指针解法
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;
    while (left < right) {
        int width = right - left;
        int length = (height[left] < height[right]) ? height[left] : height[right];
        int area = width * length;
        if (area > maxArea) maxArea = area;
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}