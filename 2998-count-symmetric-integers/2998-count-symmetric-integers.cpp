class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
         int count = 0;
        
        for (int num = low; num <= high; num++) {
            string numStr = to_string(num);
            int n = numStr.length();
            
            
            if (n % 2 == 1) {
                continue;
            }
            
            int sum1 = 0, sum2 = 0;
            int half = n / 2;
            
            for (int i = 0; i < half; i++) {
                sum1 += numStr[i] - '0'; 
                sum2 += numStr[i + half] - '0';
            }
            
            if (sum1 == sum2) {
                count++;
            }
        }
        
        return count;  
    }
};