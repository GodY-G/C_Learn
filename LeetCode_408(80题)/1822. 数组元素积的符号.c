int signFunc(double product){
    if(product > 0 ){
        return 1;
    }else if(product < 0){
        return -1;
    }else{
        return 0;
    }
}

int arraySign(int* nums, int numsSize) {
    double product = 1;
    for(int i = 0;i < numsSize;++i){
        product *= nums[i];
    }
    return signFunc(product);
}