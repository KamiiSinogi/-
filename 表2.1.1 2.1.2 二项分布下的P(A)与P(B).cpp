#include<algorithm>
#include<iostream>
#include<iomanip>
#include<complex>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<bitset>
#include<ctime>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 10039
#define mod 20070831
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll C[39][39];
ll power(ll i,ll j)
{
	ll res=1;
	for(int a=1;a<=j;a++) res*=i;
	return res;
}
double calc(int n,int p)
{
	ll res=0;
	for(int a=0;a<=n;a++)
	{
		res+=power(C[n][a]*power(p,a)*power(10-p,n-a),2);
//		if(a) res+=C[n][a]*power(p,a)*power(10-p,n-a)*C[n][a-1]*power(p,a-1)*power(10-p,n-a+1)*2;
	}
	return 1-(double)res/power(10,n<<1);
}
int main()
{
	for(int a=0;a<39;a++) C[a][0]=1;
	for(int a=1;a<39;a++)
	{
		for(int b=1;b<=a;b++)
		{
			C[a][b]=C[a-1][b-1]+C[a-1][b];
		}
	}
	for(int a=1;a<=9;a++)
	{
		for(int b=1;b<=9;b++)
		{
			printf("%0.4lf ",calc(a,b));
		}
		cout<<endl;
	}
	return 0;
}
/*Kamii_Sinogi*/