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
	ll n, b, given, token, val;
	while (cin >> b >> n)
	{
		map<int, ll>mp;
		map<int, ll>::iterator it;
		if (n == 0 && b == 0)
			break;
		rep(i, b)
		{
			ll a;
			cin >> a;
			mp[i + 1] += a;
		}
		rep(i, n)
		{
			cin >> given >> token >> val;
			mp[given] -= val, mp[token] += val;
		}
		bool test = 0;
		for (it = mp.begin(); it != mp.end();it++)
		{
			if (it->second < 0)
			{
				cout << "N" << endl;
				test = 1;
				break;
			}
		}
		if (!test)
			cout << "S" << endl;
	}
	return 0;
}
