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
#define N 10000039
#define mod 20070831
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
double dp[N];
double K(double p)
{
	return 1.0548*p*p+0.0551*p;
}
double calc(double p)
{
	double k=K(p),stp,res=0;
	for(int a=1;a<=N-39;a++)
	{
		stp=1,dp[a]=0;
		for(int b=1;b<=a && stp>1e-6;b++)
		{
			dp[a]+=dp[a-b]*stp*min(b*k,1.0);
			stp*=1-min(b*k,1.0);
		}
		res+=dp[a];
	}
	return res;
}
int main()
{
	dp[0]=1; 
	for(int a=1;a<=9;a++)
	{
		printf("%lf\n",calc(0.1*a));
	}
}
/*Kamii_Sinogi*/