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
	ll x;
	while (cin >> x && x != 0)
	{
		string a, b;
		int c = 1;
		while (x)
		{
			if (!(x & 1))
				a = '0' + a, b = '0' + b;
			else
			{
				if (c & 1)
					a = '1' + a, b = '0' + b;
				else
					b = '1' + b, a = '0' + a;
				c++;
			}
			x >>= 1;
		}
		bitset<32>a1(a);
		bitset<32>b1(b);
		cout << a1.to_ullong() << " " << b1.to_ullong() << endl;
	}
	return 0;
}
