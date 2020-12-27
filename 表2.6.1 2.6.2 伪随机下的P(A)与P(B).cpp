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
double A[39],stp[39],ans[39][39];
double K(double p)
{
	return 1.0548*p*p+0.0551*p;
}
void dfs(int now,int w,double p,int lim)
{
	if(now==lim)
	{
		stp[w]+=p;
		return;
	}
	dfs(lim,w,p*A[lim+1-now],lim);
	for(int a=1;a<=lim-now;a++)
	{
		dfs(now+a,w+1,p*A[a]*min(a*A[0],1.0),lim);
	}
}
double calc(int n)
{
	double res=1;
	for(int a=0;a<=n;a++)
	{
		res-=stp[a]*stp[a];
//		if(a) res-=stp[a-1]*stp[a]*2;
	}
	return res;
}
int main()
{
	for(int a=1;a<=9;a++)
	{
		A[0]=K(0.1*a),A[1]=1;
		for(int b=2;b<=10;b++) A[b]=A[b-1]*(1-min((b-1)*A[0],1.0));
		for(int b=1;b<=9;b++)
		{
			for(int c=0;c<=b;c++) stp[c]=0;
			dfs(0,0,1,b);
			ans[b][a]=calc(b);
		}
	}
	for(int a=1;a<=9;a++)
	{
		for(int b=1;b<=9;b++)
		{
			printf("%.4lf ",ans[a][b]+1e-7);
		}
		cout<<endl;
	}
	return 0;
}
/*Kamii_Sinogi*/