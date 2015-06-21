#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

#define pb push_back
#define fs first
#define sc second

int n, m;
const double EPS = 1e-5;

class Squares {
public:
    bool isNguyen(double a) {
        return (fabs(a-(int)a) < EPS);
    }

    bool inside(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int countSquares( vector <string> a ) {
        m = a[0].size(), n = a.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k)
            for (int l = 0; l < m; ++l)
            if ((k!=i || l!=j) && a[k][l]==a[i][j]) {
                double mx = ((double)i+k)/2.0, my = ((double)j+l)/2.0;
                double vtx = ((double)l-j)/2.0, vty = ((double)i-k)/2.0;
                double ax = mx+vtx, ay = my+vty;
                double bx = mx-vtx, by = my-vty;
                if (isNguyen(ax)&&isNguyen(ay)&&isNguyen(bx)&&isNguyen(by)) {
                    int cx = (int)ax, cy = (int)ay, dx = (int)bx, dy = (int)by;
                    if (inside(cx,cy)&&inside(dx,dy)&&a[cx][cy]==a[dx][dy]&&a[dx][dy]==a[i][j])
                        ++cnt;
                }
            }
        }
        return cnt/4;
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string field[]            = {"ABA", "BAB", "ABA"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {"AA", "AA"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"ABC", "DEF", "GHI"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"AABCA", "AAAAA", "BAAAB", "AAAEA", "ADBFA"};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Squares().countSquares(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE

