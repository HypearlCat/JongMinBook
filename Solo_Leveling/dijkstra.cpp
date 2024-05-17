#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int number = 4;
int INF = 1000000000;

//간선 정보
vector<pair<int, int>> a[5];
int dp[5];

void dijkstra(int start) {
	dp[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
	pq.push(make_pair(1, 0));

	while (!pq.empty()) {
		int currNode = pq.top().first;
		int distance = pq.top().second;

		pq.pop();
		
		if (distance > dp[currNode]) continue;
		for (int i = 0;i < a[currNode].size();i++) {
			int nextNode = a[currNode][i].first;
			int nextDistance = a[currNode][i].second + dp[currNode];
			
			if (nextDistance < dp[nextNode]) {
				dp[nextNode] = nextDistance;
				pq.push(make_pair(nextNode, nextDistance));
			}
		}

	}
}

int main(void) {
	for (int i = 1;i <= number;i++) dp[i] = INF;

	a[1].push_back(make_pair(2, 3));
	a[1].push_back(make_pair(3, 6));
	a[1].push_back(make_pair(4, 7));

	a[2].push_back(make_pair(1, 3));
	a[2].push_back(make_pair(3, 1));

	a[3].push_back(make_pair(2, 1));
	a[3].push_back(make_pair(1, 6));
	a[3].push_back(make_pair(4, 1));

	a[4].push_back(make_pair(1, 7));
	a[4].push_back(make_pair(3, 1));

	dijkstra(1);

	for (int i = 1;i <= number;i++) cout << "Node" << i << ":" << dp[i] << endl;
}