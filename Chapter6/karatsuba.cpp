#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);
	for (int i = 0;i + 1 < num.size();i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}

		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}

	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0;i < a.size();i++) {
		for (int j = 0;j < b.size();j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;

}



void addTo(vector<int>& a, const vector<int>& b, int k) {
	vector<int> ten_k(k + 1, 0);
	ten_k[k] = 1;
	vector<int> middle_ans;
	middle_ans = multiply(b, ten_k);
	a.resize(max(middle_ans.size(), a.size()));

	for (int i = 0;i < middle_ans.size();i++) {
		a[i] += middle_ans[i];
	}

	normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
	for (int i = 0;i < b.size();i++) {
		a[i] -= b[i];
	}
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);

	vector<int>z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;

}

int main(void) {
	vector<int> a(100,1);
	vector<int> b(100,2);

	vector<int> ans;
	ans = karatsuba(a, b);
	for (int i = ans.size()-1;i > -1;i--) {
		cout << ans[i];
	}

	return 0;
}