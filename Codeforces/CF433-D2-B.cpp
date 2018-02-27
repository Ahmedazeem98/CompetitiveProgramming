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
	int x, q, a, b, c;
	cin >> x;
	vector<ll>v(x);
	vector<ll>one(x);
	vector<ll>two(x);
	rep(i, x)
		cin >> v[i];
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)
			two[i] = v[i];
		else
			two[i] = two[i - 1] + v[i];
	}
	sort(allv(v));
	for (int i = 0; i < v.size(); i++)
	{
		if (!i)
			one[i] = v[i];
		else
			one[i] = v[i] + one[i - 1];
	}
	cin >> q;
	rep(i, q)
	{
		cin >> a >> b >> c;
		if (a == 2)
		{
			b-=2, c--;
			if (b < 0)
				cout << one[c] << endl;
			else
				cout << one[c] - one[b] << endl;
		}
		else
		{
			b-=2, c--;
			if (b < 0)
				cout << two[c] << endl;
			else
				cout << two[c] - two[b] << endl;
		}
	}
	return 0;
}
