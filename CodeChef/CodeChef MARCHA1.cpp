#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
#include <sstream>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <utility> 
#include <stdlib.h>  //atoi
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define allr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
//x = atoi(s.c_str())
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vector<int>v(x);
		rep(i, x)
			scanf("%d", &v[i]);
		bool test = 0;
		for (int i = 0; i < (1 << x); i++)
		{
			int j = i, c = 0;
			ll sum = 0;
			while (j)
			{
				if (j & 1)
					sum += v[c];
				j >>= 1;
				c++;
			}
			if (sum == y)
			{
				printf("Yes\n");
				test = 1;
				break;
			}
		}
		if (!test)
			printf("No\n");
	}
	return 0;
}
