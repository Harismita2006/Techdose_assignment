#include <iostream>
using namespace std;
int main() {
     int num;
     cout<<"Enter a number:"<<endl;
     cin>>num;
     for(int i=2;i*i<=num;i++)
     {
         if(num%i==0)
         {
             cout<<"It is not a  prime number";
             exit(0);
         }
     }
     cout<<"It is a prime number";
    return 0;
}
