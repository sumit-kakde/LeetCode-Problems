class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int n=piles.size();
        int l=1;
        double sum;
        int ans;
        int r=INT_MIN;
        for(int i=0;i<n;i++)
            r=max(r,piles[i]);
        while(l<=r)
        {
            sum=0;
            int mid=l+(r-l)/2;
            for(int i=0;i<n;i++)
                sum+=ceil((double)piles[i]/mid);

            if(sum<=h)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;   
    }
};