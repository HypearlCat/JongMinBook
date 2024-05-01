#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

int n, triangle[100][100];
int cache[100][100];

int path(int y, int x) {

	if (y == n - 1) return triangle[y][x];
	if (cache[y][x]) return cache[y][x];
	return cache[y][x] = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		//cache 초기화
		memset(cache, 0, sizeof(cache));

		int length;
		cin >> length;
		n = length;
		int cnt = 0;
		
		for (int i = 0;i < length;i++) {
			for (int j = 0;j <= i;j++) {
				cin >> triangle[i][j];
			}
		}

		cout << path(0, 0) << "\n";
		cnt++;
	}
	return 0;
}