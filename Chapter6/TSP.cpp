#include <iostream>
#include <vector>

using namespace std;
int C;
int N;

double dist[10][10];

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {
    if (path.size() == N) return currentLength;
    double ret = 999999;
    for (int next = 0;next < N;next++) {
        if (visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(void) {


    cin >> C;
    for (int i = 0;i < C;i++) {
        cin >> N;
        for (int j = 0;j < N;j++) {
            for (int k = 0;k < N;k++) {
                double input = 0;
                cin >> input;
                dist[j][k] = dist[k][j] = input;
            }
        }    

        double s = 99999;
        for (int i = 0;i < N;i++) {
            vector<bool> visited(10, false);
            visited[i] = true;
            vector<int> path;
            path.push_back(i);
            s = min(shortestPath(path, visited, 0),s);
        }
           
        cout << fixed;
        cout.precision(10);
        cout << s << "\n";
 

    }

    return 0;
}