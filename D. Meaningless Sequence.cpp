#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

long long p[3001][3001],c;
string aa;
long long mi[3005];
int main()
{
	for(int i=0; i<=3000; ++i)
		p[i][0]=1;
	for(int i=1; i<=3000; ++i)
		for(int j=1; j<=i; ++j)
			p[i][j]=(p[i-1][j]+p[i-1][j-1])%mod;
	cin>>aa;
	cin>>c;
	mi[0]=1;
	for(int i=1;i<=3001;i++)
	{
		mi[i]=((c%mod)*(mi[i-1]%mod))%mod;
	}
	long long ans=0,ji=0;
	for(int i=0; i<aa.size(); i++)
	{
		if(aa[i]=='1')
		{
			for(int j=0; j+i<aa.size(); j++)
			{
				ans+=(p[aa.size()-i-1][j]*mi[j+ji])%mod;
			}
			ji++;
		}
	}
	cout<<(ans+mi[ji])%mod;
	return 0;
}
