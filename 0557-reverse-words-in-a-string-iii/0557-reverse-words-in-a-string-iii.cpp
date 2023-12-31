class Solution {
public:
     void swap_str(string& s, int start, int end){
        int left = start, right = end;
        while(left<=right){
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
    
    string reverseWords(string s) {
        if(s.size()==1)
            return s;
        int start=0,end=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){//stop
                swap_str(s,start,i-1);
                start = i+1;
            }else if(i == s.size()-1){
                swap_str(s,start,i);
            }
        }
        
        return s;
    }
};