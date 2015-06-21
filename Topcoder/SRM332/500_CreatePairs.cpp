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

class CreatePairs {
public:
    int maximalSum( vector <int> a ) {
        int n = a.size();
        if (n==1) return a[0];
        sort(a.begin(),a.end());
        int sum = 0;
        while (n > 1 && a[n-1] > 1 && a[n-2] > 1) {
            sum += a[n-1]*a[n-2];
            n -= 2;
        }
        if (a[n-1] > 1)
            sum += a[--n];
        while (a[n-1]==1) {
            sum++;
            n--;
        }
        int i = 0;
        while (i < n && a[i] < 0 && a[i+1] < 0) {
            sum += a[i]*a[i+1];
            i += 2;
        }
        if (n-i==1) return sum+a[i];
        return sum;
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
			int data[]                = {-2, -2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int data[]                = {-1, 1, 2, 3};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int data[]                = {-1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int data[]                = {-1, 0, 1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int data[]                = {1, 1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int data[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int data[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int data[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CreatePairs().maximalSum(vector <int>(data, data + (sizeof data / sizeof data[0])));
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

