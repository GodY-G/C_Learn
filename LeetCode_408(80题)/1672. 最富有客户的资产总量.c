int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int sum = 0;
    int max = 0;
    for(int i = 0;i < accountsSize;++i){
        for(int j = 0;j < *accountsColSize;++j){
            sum += accounts[i][j];
            if(max < sum){
                max = sum;
            }
        }
        sum = 0;
    }
    return max;
}