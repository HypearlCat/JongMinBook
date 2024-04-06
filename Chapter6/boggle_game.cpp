#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
vector <vector<char>> graph = { {'U','P','L','P','M'},{'X','P','R','E','T'},{'G','I','A','E','T'},{'X','T','N','Z','Y'},{'X','O','Q','R','S'} };
vector <vector<int>> visited(5, vector<int>(5, 0));
queue <pair<int, int>> Queue;
int dx[] = { -1,1,0,0,-1,1,-1,1 };
int dy[] = { 0,0,1,-1,1,1,-1,-1 };
int word_count = 1;


bool hasWord(int x, int y, string word) {
	Queue.push(make_pair(x, y));
	visited[x][y] = 1;
	if (graph[x][y] != word[0]) return false;

	while (!Queue.empty()) {
		pair<int, int> now = Queue.front();
		Queue.pop();

		for (int i = 0;i < 8;i++) {
			int nx = dx[i] + now.first;
			int ny = dy[i] + now.second;
			if (nx < 0 or ny < 0 or nx>4 or ny>4) continue;
			if (graph[nx][ny] == word[word_count]) {
				word_count++;
				visited[nx][ny] = 1;
				Queue.push({ nx,ny });
			}
		}
	}
	if (word.size() == word_count) return true;
	else return false;

}

int main() {
	string word;
	cin >> word;

	cout << hasWord(1,1,word);

	return 0;
}