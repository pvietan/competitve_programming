#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

ll n, m, a;

int main() {
	freopen("input.txt","r",stdin);
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    cout << (n/a - (n%a==0) + 1) * (m/a - (m%a==0) + 1) << endl;
	return 0;
}
