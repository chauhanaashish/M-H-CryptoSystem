#include <cstdlib>
#include <iostream>
//#include <iostream>
#include <chrono>
 
using namespace std;
 
int main() 
//int main1(int N)
{
    
    
    int rep;                                     // to show multiple test at same time
    //cin>>N;
    rep=10;
    int Nn;
    Nn=3*rep;
    int c=0;
    double timestamp[Nn];                       // to store time taken by every function 
    
for (int q = 1; q <= rep; q++)
{
    int N=q;

  long long int x;
  //long long int N;
  cout<<"\n the size of array "<<N<<"\n";
  long long int sum=0;
//  
  long long int pubarr[N];
  long long int pvtarr[N];
  long long int tmp=0;
//private key generation

auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < N; i++)
        {
x=rand()%10+1;
tmp+=x+sum;
pvtarr[i]=tmp;
sum+=tmp;
cout << pvtarr[i] << " ";                    // pvtarr is private key array
}
cout<<"\nsum= "<<sum;
long long int temp;
long long int m;
temp=rand()%50+15;
m=sum+temp;                                   //  m is random no. greater than sum
cout<<"\n m= "<<m<<"\n";
int n;

n=31;                                         //  n is prime  no. gcd 1

// public key generation

for (int i = 0; i < N; i++)
{
pubarr[i]=(pvtarr[i]*n)%m;
cout<<pubarr[i]<<" ";                      //pubarr  is private key arrray
}
cout<<"\n";

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "key generation elapsed time: " << elapsed_seconds.count() << "s\n";
    timestamp[c++]=elapsed_seconds.count();

//encryption
 auto start1 = std::chrono::steady_clock::now();
long long int message[N];
long long int encrypted=0;
for (int i = 0; i < N; i++)
{
message[i]=rand()%2;                                               // generating random message
cout<<message[i]<<" ";
encrypted+=message[i]*pubarr[i];
}
cout<<"\n encrypted "<<encrypted<<"\n";
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1-start1;
    std::cout << " encryption elapsed time: " << elapsed_seconds1.count() << "s\n";
    timestamp[c++]=elapsed_seconds1.count();

// decryption
auto start2 = std::chrono::steady_clock::now();
long long int inverse=1;
while(true)
{
if((n*inverse)%m==1)
break;
inverse++;
}
cout<<"inverse is "<<inverse<<"\n";
temp=(encrypted*inverse)%m;
cout<<"temp after decryption "<<temp<<"\n";
long long int decryptarr[N];

for(int i=N-1;i>=0;i--)
{
if(pvtarr[i]<=temp)
{
temp-=pvtarr[i];
decryptarr[i]=1;
}
else{
decryptarr[i]=0;
}
}
   
for (int i = 0; i <= N; i++)
{
cout<<" "<<decryptarr[i];
}
cout<<"\n";
 auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2-start2;
    std::cout << "decryption elapsed time: " << elapsed_seconds2.count() << "s\n";
    timestamp[c++]=elapsed_seconds2.count();
cout<<"\n ************************ \n";
}

for(int j=0;j<3*rep;j++)
cout<<(j/3)+1<<" "<<timestamp[j]<<"  ";
cout<<"\n ************************ \n";
return 0;
}

