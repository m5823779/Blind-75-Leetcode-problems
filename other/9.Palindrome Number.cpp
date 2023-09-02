class Solution {
public:
    bool isPalindrome(int x) {
        
        // method 1: --------------------------------------------
//         if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        
//         int x_reverse = 0;
//         int tmp = x;
//         while (tmp) {
//             x_reverse *= 10;
//             x_reverse += tmp % 10;
//             tmp /= 10;
//         }
        
//         return (x_reverse == x) ? true : false;
        
        // method 2: --------------------------------------------
         if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        
        int sum = 0;
        
        while(x > sum) {
            sum *= 10;
            sum += x % 10;
            x /= 10;
        }
        
        return (x == sum) || (x == (sum / 10));
        //        even              odd

    }
};