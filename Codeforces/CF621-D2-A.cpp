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
int freq[52];
int main()
{
	fast();
	int x;
	vector<int>odd;
	vector<int>even;
	cin >> x;
	rep(i, x)
	{
		int a;
		cin >> a;
		if (a % 2)
			odd.pb(a);
		else
			even.pb(a);
	}
	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());
	ll sum = 0;
	int c = 0, t = 0;
	rep(i, odd.size() - bool(odd.size() % 2))
		sum += odd[i], t++;
	t = odd.size() - t;
	c = even.size();
	int idx1 = t - 1, idx2 = 0;
	while (t > 1 && c)
	{
		sum += odd[idx1] + odd[idx1] + even[idx2++];
		c--, t -= 2, idx1 += 2;
	}
	while (c)
		sum += even[idx2++], c--;
	cout << sum << endl;
	return 0;
}
