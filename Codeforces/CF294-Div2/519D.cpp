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
typedef pair<int,ll> ii;

map <ii,int> SL;
int f[500];
ll sum[100005];
char s[100005], a[100005];

int main() {
	freopen("input.txt","r",stdin);
    for (char i = 'a'; i <= 'z'; ++i)
        scanf("%d",f+i);
    scanf("\n%s",s);
    int L = strlen(s);
    for (int i = 1; i <= L; ++i)
        a[i] = s[i-1];
    for (int i = 1; i <= L; ++i)
        sum[i] = sum[i-1] + f[a[i]];
    SL[ii(a[1]-'a',sum[1])]++;
    ll res = 0;
    for (int i = 3; i <= L; ++i) {
        res += SL[ii(a[i]-'a',sum[i]-f[a[i]])];
        SL[ii(a[i-1]-'a',sum[i-1])]++;
    }
    for (int i = 1; i < L; ++i)
        res += (a[i]==a[i+1]);
    cout << res << endl;
    return 0;
}
