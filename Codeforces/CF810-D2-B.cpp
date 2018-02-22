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
	vector<pair<ll, pair<ll, ll>>>v;
	int x, y, a, b;
	cin >> x >> y;
	rep(i, x)
	{
		cin >> a >> b;
		ll clc = min(a, b - a);
		v.pb({ clc, { a, b } });
	}
	sort(v.rbegin(), v.rend());
	ll sum = 0;
	rep(i, vz)
	{
		if (y > 0 && v[i].first > 0)
			sum += v[i].first + v[i].second.first, y--;
		else
			sum += min(v[i].second.first,v[i].second.second);
	}
	cout << sum << endl;
	return 0;
}
