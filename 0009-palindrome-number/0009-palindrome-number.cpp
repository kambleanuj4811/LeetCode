class Solution {
public:
    bool isPalindrome(int x) {
        // ❌ Negative numbers and numbers ending in 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        // ✅ Reverse only half the number to avoid overflow and unnecessary work
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // ✅ If number of digits is odd, reversedHalf/10 removes the middle digit
        return (x == reversedHalf) || (x == reversedHalf / 10);
    }
};
