#include <iostream>
using namespace std;
int main() {
     int num;
     cout<<"Enter a number:"<<endl;
     cin>>num;
     int arr[num+1];
     fill(arr,arr+num+1,1);
     for(int i=2;i*i<=num;i++)
     {
         if(arr[i]==1)
         {
             for(int j=2;j*i<=num;j++)
             {
                 arr[i*j]=0;
             }
         }
     }
     for(int i=2;i<=num;i++)
     {
         if(arr[i]==1)
         {
         cout<<i<<" ";
         }
     }
    return 0;
}
--------------------------------------
//Segmented sieve
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> se(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]==true) {
            for (int j = 2; i*j <= n; j++) {
                isPrime[i*j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
vector<int> sieve(int l,int r)
{
    vector<int>primes=se(sqrt(r));
    vector<bool>segsieve(r-l+1,true);
    for(int p:primes)
    {
        for(int d=l/p;p*d<=r;d++)
        {
            segsieve[p*d-l]=false;
        }
    }
    vector<int>ans;
    for(int i=0;i<r-l+1;i++)
    {
        if(segsieve[i]==true)
        {
            ans.push_back(i+l);
        }
    }
    return ans;
    
}
int main() {
     int num1,num2;
     cout<<"Enter the range:"<<endl;
     cin>>num1>>num2;
     vector<int>res=sieve(num1,num2);
     for(int i:res)
     {
         cout<<i<<" ";
     }
    return 0;
}
