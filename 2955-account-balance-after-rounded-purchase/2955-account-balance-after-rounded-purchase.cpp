class Solution {
public:
    int accountBalanceAfterPurchase(int num) {
     return 100 - ((num % 10 >= 5) ? ((num+9)/10)*10 : (num/10)*10);   
    }
};