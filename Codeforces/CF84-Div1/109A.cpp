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

int n;

int main() {
	freopen("input.txt","r",stdin);
    int n; scanf("%d",&n);
    for (int i = n/7; i >= 0; --i) {
        int x = n - i*7;
        if (x%4==0) {
            for (int j = 1; j <= x/4; ++j)
                printf("4");
            for (int j = 1; j <= i; ++j) printf("7");
            return 0;
        }
    }
    printf("-1");
	return 0;
}
