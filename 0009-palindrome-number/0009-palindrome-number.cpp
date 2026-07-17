class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x != 0)){
            return false;
        }

        int halfreversed = 0;

        while(x > halfreversed){
            halfreversed = halfreversed*10 + x%10;
            x /= 10;
        }

        return (x == halfreversed || x == halfreversed /10);
    }
};