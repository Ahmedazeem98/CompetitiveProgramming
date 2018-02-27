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
	int x, p1 = 0, p2 = 0, po, c = 0;
	cin >> x >> po;
	vector<int>v(x);
	rep(i, x)
		cin >> v[i];
	po--;
	p1 = po + 1, p2 = po - 1;
	while (p2 >= 0 || p1 < x)
	{
		if (p2 >= 0 && p1 < x && v[p1] && v[p2])
			c += 2;
		else if (p2 < 0 && p1 < x)
			c += v[p1];
		else if (p1 >= x && p2 >= 0)
			c += v[p2];
		p2--, p1++;
	}
	c += v[po];
	cout << c << endl;
	return 0;
}
