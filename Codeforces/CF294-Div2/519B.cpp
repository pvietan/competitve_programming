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

const int N = 100005;

int a[N], b[N], c[N];

void nhap(int * a) {
    for (int i = 1; i <= a[0]; ++i)
        scanf("%d",a+i);
}

int giaiquyet(int * a, int * b) {
    for (int i = 1; i <= a[0]; ++i)
        if (a[i] != b[i]) return a[i];
}

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d",&a[0]);
    b[0] = a[0]-1;
    c[0] = b[0]-1;
    nhap(a);
    nhap(b);
    nhap(c);
    sort(a+1,a+a[0]+1); sort(b+1,b+b[0]+1); sort(c+1,c+c[0]+1);
    int res1 = giaiquyet(a,b), res2 = giaiquyet(b,c);
    if (res1 > res2) swap(res1,res2);
    cout << res1 << '\n' << res2;
	return 0;
}
