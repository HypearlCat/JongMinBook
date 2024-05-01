#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

int lis(const vector<int>& A) {

	if (A.empty()) return 0;
	int ret = 0;
	for (int i = 0;i < A.size();i++) {
		vector<int> B;
		for (int j = i + 1;j < A.size();j++) {
			if (A[i] < A[j]) {
				B.push_back(A[j]);
			}
		}
		ret = max(ret,1+lis(B));
	}
	return ret;
}

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		
		int cnt;
		cin >> cnt;
		
		vector<int> arr;
		for (int i = 0;i < cnt;i++) {
			int element;
			cin >> element;
			arr.push_back(element);
		}
		cout << lis(arr) << "\n";

	}
	return 0;
}