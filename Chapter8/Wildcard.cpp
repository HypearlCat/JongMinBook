#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int cache[101][101];

string W, S;

bool memo(int w, int s) {
	if (cache[w][s] != -1) return cache[w][s];

	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}

	if (w == W.size()) return cache[w][s] = (s == S.size());

	if (W[w] == '*') {
		if (memo(w + 1, s) || s < S.size() && memo(w, s + 1)) {
			return cache[w][s] = 1;
		}
	}
	return cache[w][s] = 0;
}

int main(void) {
	int cnt = 0;
	int T;
	cin >> T;
	vector<vector<string>> ans(T);
	while (T--) {

		cin >> W;
		int T0;
		cin >> T0;
		
		while (T0--) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (memo(0, 0)) ans[cnt].push_back(S);
		}
		sort(ans[cnt].begin(), ans[cnt].end());

		cnt++;
	}


	for (int i = 0;i < ans.size();i++) {
		for (int j = 0;j < ans[i].size();j++) {
			cout << ans[i][j] << "\n";
		}
	}
	return 0;
}