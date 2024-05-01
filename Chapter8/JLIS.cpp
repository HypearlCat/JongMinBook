#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <limits>

using namespace std;
int n,m,A[100],B[100];
int cache[501][501], S[501];
const long long NEGINF = numeric_limits<long long>::min();

int jlis(int indexA, int indexB) {

	if (cache[indexA + 1][indexB + 1] != -1) return cache[indexA + 1][indexB + 1];
	int ret = 2;
	
	long long a = indexA == -1 ? NEGINF : A[indexA];
	long long b = indexB == -1 ? NEGINF : B[indexB];
	long long maxElement = max(a, b);
	
	for (int nextA = indexA + 1;nextA < n;nextA++) {
		if (maxElement < A[nextA]) {
			ret = max(ret, 1+jlis(nextA, indexB));
		}
	}

	for (int nextB = indexB + 1;nextB < m;nextB++) {
		if (maxElement < B[nextB]) {
			ret = max(ret, 1+jlis(indexA,nextB));
		}
	}

	return cache[indexA+1][indexB+1] = ret;
}


int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int maximum = 0;

		int a;
		int b;

		cin >> a >> b;
		n = a;
		m = b;

		for (int i = 0;i < a;i++) {
			int real_element;
			cin >> real_element;
			A[i] = real_element;	
		}

		for (int i = 0;i < b;i++) {
			int real_element2;
			cin >> real_element2;
			B[i] = real_element2;
		}

		memset(cache, -1, sizeof(cache));
		cout << jlis(-1,-1)-2 << "\n";
		memset(S, 0, sizeof(S));


	}
	return 0;
}