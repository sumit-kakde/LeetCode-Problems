class Solution {
public:
    
    int maximum(vector<int>& weights){
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
    
            maxi=max(maxi,weights[i]);
        }
        return maxi;
    }
   
    int summation(vector<int>& weights){
       int res = 0;
        for (int i = 0; i < weights.size(); i++) {
            res += weights[i];
        }
        return res;
    }
    bool capacity(vector<int>& weights, int days,int cap){
        int load=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
          if((load+weights[i])>cap){
                d++;
                load=weights[i];
             }else{
                 load+=weights[i];
             }   
        }
        return d<=days;

    }
        int shipWithinDays(vector<int>& weights, int days) {
                int low=maximum(weights);
                int high=summation(weights);
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(capacity(weights,days,mid)){
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                }
                return low;
    }
};