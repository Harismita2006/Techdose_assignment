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
