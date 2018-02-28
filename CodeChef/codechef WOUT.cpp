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
#include <iomanip>
#include <fstream>
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
	cin >> t;
	while (t--)
	{
		ll n, h;
		cin >> n >> h;
		vector<ll>v(n + 2);
		v.push_back(0);
		rep(i,n)
		{
			ll a, b;
			cin >> a >> b;
			v[a + 1] -= 1, v[b + 2] += 1;
		}
		for (int i = 1; i <= n + 1; i++)
		{
			v[i] += v[i - 1];
			if (i != 1)
				v[i - 1] += n;
		}
		for (int i = 1; i <= n + 1; i++)
			v[i] += v[i - 1];
		int c = 0;
		ll mn = 10e18;
		for (int i = h; i <= n; i++)
		{
			mn = min(mn, v[i] - v[c++]);
		}
		cout << mn << endl;
	}
	return 0;
}
