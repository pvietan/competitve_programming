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

char a[1005];
int n;

int solve(char a, char b) {
    int x = a-'0', y = b-'0';
    if (x > y) swap(x,y);
    return min(y-x,x+1+9-y);
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d\n",&n);
    for (int i = 1; i <= n; ++i) scanf("%c",&a[i]);
    scanf("\n");
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        char c;
        scanf("%c",&c);
        res += solve(a[i],c);
    }
    cout << res << endl;
	return 0;
}
