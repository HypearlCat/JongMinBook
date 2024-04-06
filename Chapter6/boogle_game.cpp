#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };

vector<vector<char>> graph(5,vector<char>(5,0));

int testcase = 0;
bool hasWord(int y, int x, const string& word) {
	if (x < 0 || y < 0 || x>4 || y>4) return false;
	if (graph[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; ++direction) {
		int nx = dx[direction] + x;
		int ny = dy[direction] + y;

		if (hasWord(ny, nx, word.substr(1))) return true;
	}
	return false;
}


int main() {
	cin >> testcase;
	for (int i = 0;i < testcase;i++) {

		for (int a = 0;a < 5;a++) {
			string str;
			cin >> str;
			for (int b = 0;b < str.length();b++) {
				graph[a][b] = str[b];
			}
		}

		int N;
		cin >> N;
		for (int c = 0;c < N;c++) {
			string word;
			cin >> word;
			bool chk = false;
			for (int d = 0;d < 5;d++) {
				for (int e = 0;e < 5;e++) {
					if (hasWord(d, e, word) == true) chk = true;
				}
			}

			if (chk == true) cout << word << " " << "YES" << "\n";
			else cout << word << " " << "NO" << "\n";

		}




	}

	return 0;
}