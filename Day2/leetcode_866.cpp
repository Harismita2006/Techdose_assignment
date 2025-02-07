//Prime palindrome
class Solution {
public:
    int primePalindrome(int n) {
        int i = n;

        while (true) {
            int rev = 0;
            int num = i;

            while (num != 0) {
                rev = (rev * 10) + (num % 10);
                num = num / 10;
            }

            if (rev == i ) {
                bool isPrime = true;

                if (rev <= 2) {
                    return 2;
                }
                if(rev%2==1)
                {
                for (int j = 2; j * j <= rev; j++) {
                    if (rev % j == 0) {
                        isPrime = false;
                        break;
                    }
                }

                if (isPrime == true) {
                    return i;
                }
                }
            }
            i++;
             if (i > 11 && to_string(i).size() % 2 == 0) {
                i = pow(10, to_string(i).size());
            }
        }
    }
};
