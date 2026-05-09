char* mergeAlternately(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    char* ans = (char*)malloc((m + n + 1) * sizeof(char));

    int index =  0;
    for(int i = 0;i < n || i < m;++i){
        if(i < m){
            ans[index++] = word1[i];
        }
        if(i < n){
            ans[index++] = word2[i];
        }
    }
    ans[index] = '\0';


    return ans;
}