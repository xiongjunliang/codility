
// 第一次使用DFS来做最短路径超时
// 忘记最短路径算法啦！！！

#include <iostream>
#include <vector>
#include <set>

#include <limits.h>

using namespace std;

int solution(const vector<int> &A, const vector<int> &B, 
        const vector<int> &C, const vector<int> &D) {
        // write your code here...
    size_t N = D.size();
    size_t M = A.size();
    vector<int> cost(N, -1);
    vector<bool> visited(N, false);
    vector<vector<int> > map(N, vector<int>(N, -1));
    for (size_t i = 0; i < M; ++i) {
        if (map[A[i]][B[i]] == -1 || C[i] < map[A[i]][B[i]]) {
            map[A[i]][B[i]] = C[i];
            map[B[i]][A[i]] = C[i];
        }
    }
    cost[0] = 0;
    while (1) {
        int ind = -1;
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && cost[i] >= 0 && 
                    (ind == -1 || cost[i] < cost[ind])) {
                ind = i;
            }
        }
        if (ind == -1) {
            break;
        }
        if (cost[ind] <= D[ind]) {
            return cost[ind];
        }
        visited[ind] = true;
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && map[ind][i] != -1 && 
                    (cost[i] == -1 || (cost[ind] + map[ind][i] < cost[i]))) {
                cost[i] = cost[ind] + map[ind][i];
            }
        }
    
    }
    return -1;    
}

int main() {
    return 0;
}


