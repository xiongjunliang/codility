
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> &A) {
    // write your code here...
    set<int> l;
    set<int> lmis;
    set<int> r;
    set<int> rmis;
    int len = A.size();
    int i = 0;
    int j = A.size() - 1;
    int cnt = 0;
    while (1) {
        l.insert(A[i]);
        rmis.insert(A[i]);
        i ++;
        while (!lmis.empty() || !rmis.empty()) {
            while (!lmis.empty()) {
                if (l.find(A[i]) == l.end()) {
                    l.insert(A[i]);
                    if (lmis.find(A[i]) != lmis.end()) {
                        lmis.erase(A[i]);   
                    } else {
                        rmis.insert(A[i]);
                    }
                }
                i ++;
            }
            while (!rmis.empty()) {
                if (r.find(A[j]) == r.end()) {
                    r.insert(A[j]);
                    if (rmis.find(A[j]) != rmis.end()) {
                        rmis.erase(A[j]);
                    } else {
                        lmis.insert(A[j]);
                    }
                }
                j --;
            }
        }
        int x = 1;
        while (i < len) {
            if (l.find(A[i]) != l.end()) {
                i ++;
                x ++;
            } else {
                break;
            }
        }
        int y = 1;
        while (j >= 0) {
            if (r.find(A[j]) != r.end()) {
                j --;
                y ++;
            } else {
                break;
            }
        }
        cnt += x * y;
        if (cnt > 1000000000) {
            return 1000000000;
        }
        if (i == len) {
            break;
        } 
    }
    return cnt;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> v;
        int x;
        while (n--) {
            cin >> x;
            v.push_back(x);
        }
        cout << solution(v) << endl;
    }
    return 0;
}

