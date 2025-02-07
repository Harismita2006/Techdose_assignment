//Prime arrangements
class Solution {
public:
    int numPrimeArrangements(int n) {
        const int mod=1e9+7;
        vector <bool> isPrime(n+1,true);
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            {
            for(int j=2;i*j<=n;j++)
            {
                isPrime[i*j]=false;
            }
            }
        }
        int count=0;
        for(int i=2;i<=n;i++)
        {
            if(isPrime[i])
             {
                count=count+1;
             }
        }
        int prime_count=count;
        int non_prime_count=n-prime_count;
        long long res1=1;
        long long res2=1;
        for(int i=2;i<=prime_count;i++)
        {
            res1=(res1*i)%mod;
        }
        for(int i=2;i<=non_prime_count;i++)
        {
            res2=(res2*i)%mod;
        }
        return((res1*res2)%mod);
    }
};
