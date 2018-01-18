#include <vector>
#include <algorithm>

using namespace std;

void flood_fill(bool (&checked)[100][100], vector<vector<int>>& picture,
                int i, int j, int m, int n, int& area) {
    checked[i][j] = true;
    int curr = picture[i][j];
    if (i>0 && !checked[i-1][j] && picture[i-1][j] == curr) {
        area++;
        flood_fill(checked, picture, i-1, j, m, n, area);
    }
    if (j>0 && !checked[i][j-1] && picture[i][j-1] == curr) {
        area++;
        flood_fill(checked, picture, i, j-1, m, n, area);
    }
    if (j+1<n && !checked[i][j+1] && picture[i][j+1] == curr) {
        area++;
        flood_fill(checked, picture, i, j+1, m, n, area);
    }
    if (i+1<m && !checked[i+1][j] && picture[i+1][j] == curr) {
        area++;
        flood_fill(checked, picture, i+1, j, m, n, area);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool checked[100][100] = {false};
    int area;
    vector<int> areas;
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (!checked[i][j] && picture[i][j] != 0) {
                area = 1;
                flood_fill(checked, picture, i, j, m, n, area);
                areas.push_back(area);
                number_of_area++;
            }
        }
    }
    
    max_size_of_one_area = *max_element(areas.begin(), areas.end());
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
