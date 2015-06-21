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

map <string,int> F, G;
string s[1005];
int n, x[1005];

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d\n",&n);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        char c; scanf("%c",&c);
        scanf("%d\n",&x[i]);
        F[s[i]] += x[i];
    }
    int mx = -1;
    for (map<string,int> ::iterator it = F.begin(); it != F.end(); it++) {
        string s = it->first; int point = it->second;
        mx = max(mx,point);
    }
    string res;
    for (int i = 1; i <= n; ++i) {
        G[s[i]] += x[i];
        if (G[s[i]]>=mx && F[s[i]]==mx) {
            cout << s[i] << endl;
            return 0;
        }
    }
	return 0;
}
