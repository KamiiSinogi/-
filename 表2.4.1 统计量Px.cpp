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
int n,num[39];
int main()
{
	scanf("%d",&n);
	for(int a=1,b;a<=n;a++)
	{
		scanf("%d",&b);
		num[0]++,num[b]++;
	}
	printf("tot\t%d\n",num[0]);
	for(int a=1;a<=10;a++)
	{
		printf("%d\t%d\n",a,num[a]);
	}
	for(int a=1;a<=10;a++)
	{
		printf("%d\t%lf\n",a,num[a]*1.0/num[0]);
		num[0]-=num[a];
	}
	return 0;
}
/*Kamii_Sinogi*/