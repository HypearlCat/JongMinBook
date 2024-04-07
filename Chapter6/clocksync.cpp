#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 9999, SWITCHES = 10;

const char linked[SWITCHES][16 + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool areAligned(const vector<int>& clocks) {
    for (int i = 0; i < 16; i++) {
        if (clocks[i] != 12) return false;
    }
    return true;
}

void push(vector<int>& clocks, int swtch) {
    for (int clock = 0; clock < 16; clock++) {
        if (linked[swtch][clock] == 'x') {
            clocks[clock] += 3;
        }

        if (clocks[clock] == 15) {
            clocks[clock] = 3;
        }
    }
}

int solved(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++) {
        ret = min(ret, cnt + solved(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        vector<int> clock;
        for (int i = 0; i < 16; i++) {
            int x;
            cin >> x;
            clock.push_back(x);
        }
        int ans = solved(clock, 0);

        if (ans >= INF) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}