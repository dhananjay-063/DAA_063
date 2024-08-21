#include<iostream>
using namespace std;
class zero
{
public :
int check(int p,int n);
void find(int n);
};
int zero :: check(int p, int n)
{
int count=0,f=5;
while(f<=p)
{
count+=p/f;
f=f*5;
}
return(count>=n);
}
void zero :: find(int n)
{
int low,high,mid;
if(n==1)
{
cout<<"Number : 5 "<<endl;
return;
}
low=0;
high=n*5;
while(low<high)
{
mid=(low+high)/2;
if(check(mid,n))
{
high=mid;
}
else
{
low=mid+1;
}
}
cout<<"Number : "<<low<<endl;
}
int main()
{
zero z;
int n;
cout<<"Number of zero : ";
cin>>n;
z.find(n);
return 0;
}
