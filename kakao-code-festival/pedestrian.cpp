#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    int h[501][501];
    int v[501][501];
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (i==1 && j==1) {
                h[i][j] = 1;
                v[i][j] = 1;
            } else if (city_map[i-1][j-1] == 1) {
                h[i][j] = 0;
                v[i][j] = 0;
            } else if (city_map[i-1][j-1] == 2) {
                h[i][j] = h[i][j-1];
                v[i][j] = v[i-1][j];
            } else {
                h[i][j] = (h[i][j-1] + v[i-1][j]) % MOD;
                v[i][j] = (h[i][j-1] + v[i-1][j]) % MOD;
            }
        }   
    }
    
    answer = h[m][n];
    
    return answer;
}
