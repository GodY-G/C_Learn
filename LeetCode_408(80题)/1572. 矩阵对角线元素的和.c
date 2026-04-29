int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    for(int i = 0;i < matSize;++i){
            if(matSize % 2 == 0){
                sum += (mat[i][i] + mat[i][*matColSize - i - 1]);
            }else{
                if(i == matSize / 2){
                    sum += mat[i][i];
                }else{
                    sum += (mat[i][i] + mat[i][*matColSize - i - 1]);
                }
            }
    }
    return sum;
}