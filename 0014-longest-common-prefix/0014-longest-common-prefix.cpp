class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        sort(strs.begin(),strs.end());
        string start=strs[0];
        int n=strs.size();
        string end=strs[n-1];
        for(int i=0;i<min(start.length(),end.length());i++){
            if(start[i]!=end[i]){
                return res;
            }else{
                res+=end[i];
            }
        }
        return res;
    }
};