class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge;
        int i=0;
        int j=0;
        while(i<word1.size()||j<word2.size()){
            if (i<word1.size()){
                merge=merge+word1[i];
                i++;
            }
            if(j<word2.size()){
                merge=merge+word2[j];
                j++;
            }
        }    
        return merge;
    }
};