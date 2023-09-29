class Solution {
public:
    bool isMonotonic(vector<int>& a) {
       int n = a.size(); 
        if(n<2) return 1; 
        int d = 0 ; 
        for(int i = 1 ; i < n ; i++){ 
            if(a[i] == a[i-1]) continue; 
            if(a[i] > a[i-1]){ 
                if(!d || d==1) d = 1; 
                else return 0; 
            }else{ 
                if(!d || d==-1) d = -1; 
                else return 0; 
            } 
        } 
        return 1;
    }
};