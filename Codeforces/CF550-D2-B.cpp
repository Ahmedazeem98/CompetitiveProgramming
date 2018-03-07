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
	int n, l, r, x, sol = 0;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	vector<ll>v(n);
	rep(i, n)
		scanf("%d", &v[i]);
	for (int i = 0; i < (1 << n); i++)
	{
		int j = i, k = j, h = 0;
		while (k)
		{
			if (k & 1)
				h++;
			k >>= 1;
		}
		if (h > 1)
		{
			ll mx = LONG_MIN, mn = LONG_MAX, sum = 0, c = 0;
			while (j)
			{
				if (j & 1)
					sum += v[c], mx = max(mx, v[c]), mn = min(mn, v[c]);
				j >>= 1;
				c++;
			}
			if (sum >= l && sum <= r && mx - mn >= x)
				sol++;
		}
	}
	printf("%d\n", sol);
	return 0;
}
