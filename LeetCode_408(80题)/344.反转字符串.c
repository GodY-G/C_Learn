void reverseString(char* s, int sSize) {
    int l = 0;
    int r = sSize - 1;
    while(l < r){
        char temp;
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        r--;
        l++;
    }
}