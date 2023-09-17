class Solution {
public:
    bool possible(vector<int> bloomDay,int m, int k,int day){
        int count =0;
        int bq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }else{
                bq+=count/k;
                count=0;
            }
        }
        bq+=count/k;
        return bq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        if(bloomDay.size()<val){
            return -1;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,m,k,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        
        }
            return low;
    }
};