#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// you can also use includes, for example:
vector<int> uniq_present(vector<int> v) {
    int i = 0;
    int j = 1;
    int k = 0;
    int n = v.size();
    while (i < n && j < n && k < n) {
        int t = v[(i+k)%n] - v[(j+k)%n];
        if (t == 0) {
            k++;
        } else {
            if (t > 0) {
                i = i + k + 1;
            } else {
                j = j + k + 1;
            }
            if (i == j) {
                j ++;
            }
            k = 0;
        }
    }
    i = min(i, j);
    vector<int> r;
    r.resize(n);
    for (int j = 0; j < n; ++j) {
        r[j] = v[(i+j)%n];
    }
    return r;
}

int solution(const vector< vector<int> > &A, int P) {
    map<vector<int>, int> counter;
    int ret = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        // cout << i << endl;
        vector<int> v = A[i];
        sort(v.begin(), v.end());
        vector<int> s;
        s.resize(v.size());
        for (int j = 1; j < v.size(); ++j) {
            s[j] = v[j] - v[j-1];
        }
        s[0] = v[0] - v[v.size() - 1] + P;
        vector<int> p = uniq_present(s);
        // cout << "ret=" << ret << endl;
        if (counter.find(p) != counter.end()) {
            ret += counter[p];
            counter[p] ++;
        } else {
            counter.insert(make_pair(p, 1));
        }
    }
    return ret;
}

int main() {
    return 0;
}


