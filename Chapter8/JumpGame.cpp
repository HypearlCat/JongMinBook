#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int cache[101][101];
int N;
int board[101][101];

int jump2(int y, int x) {
	if (y >= N || x >= N) return 0;
	if (y == N-1 && x== N-1) return 1;
	if (cache[y][x] != -1) return cache[y][x];
	int jumpSize = board[y][x];
	return cache[y][x] = jump2(y + jumpSize, x) || jump2(y, x + jumpSize);

}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N1;
		cin >> N1;
		N = N1;
		memset(board, -1, sizeof(cache));
		memset(cache, -1, sizeof(cache));
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				cin >> board[i][j];
			}
		}	
		if (jump2(0, 0)) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}