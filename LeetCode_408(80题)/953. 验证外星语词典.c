#include <stdbool.h>
#include <string.h>

bool isAlienSorted(char** words, int wordsSize, char* order) {
    //建立字母映射表
    int rank[26];
    for(int i = 0;i < 26;++i){
        rank[order[i] - 'a'] = i;
    }

    for(int i = 0;i < wordsSize - 1;++i){
        char* word1 = words[i];
        char* word2 = words[i+1];
        int len1 = strlen(word1);
        int len2 = strlen(word2);
        bool is_same = true;

        for(int j = 0;j < len1&&j < len2;++j){
            char c1 = word1[j];
            char c2 = word2[j];

            if(c1 != c2){
                if(rank[c1 - 'a'] > rank[c2 - 'a']){
                    return false;
                }
                is_same = false;
                break;
            }
        }
        if(is_same && len1 > len2){
            return false;
        }
    }

    return true;
}