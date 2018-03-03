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
#include<fstream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <utility>   // std::pair, std::make_pair
#include <stdlib.h>  //atoi
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
//x = atoi(s.c_str())
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
bool iSprime(int d)
{
	int t = 0;
	for (int i = 2; i*i <= d; i++)
	{
		if (d%i == 0)
		{
			t = 1;
			break;
		}
	}
	if (!t)
		return 1;
	else
		return 0;
}
int main()
{
	fast();
	int x, y, z;
	cin >> x >> y >> z;
	ll sum = 0;
	map<int, int>mp;
	rep(i, x)
	{
		rep(j, y)
		{
			rep(k, z)
			{
				ll clc = (i + 1)*(j + 1)*(k + 1), l = 1, cnt = 0;
				if (mp[clc])
				{
					sum += mp[clc];
					continue;
				}
				for (; l*l < clc; l++)
				{
					if (clc%l == 0)
						cnt += 2;
				}
				if (clc%(l*l) == 0)
					cnt++;
				sum += cnt;
				sum %= 1073741824;
				mp[clc] = cnt;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
