#include <iostream>
#include <vector>
using namespace std;

bool w[101][101];
int T, R, C, H, V;

int main() {
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        cin >> R >> C >> H >> V;
        char tmp;
        int total = 0;
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                cin >> tmp;
                if (tmp == '@') {
                    w[r][c] = true;
                    total++;
                } else {
                    w[r][c] = false;
                }
            }
        }
        if (total % (H+1) || total % (V+1)) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        if (total == 0) {
            cout << "POSSIBLE\n";
            continue;
        }

        int cnum_r = total / (H+1);
        int cnum_c = total / (V+1);
        int cnum_p = total / ((H+1) * (V+1));

        // horizontal cut check
        int choco_in_piece = 0;
        bool is_possible = true;
        vector<int> rowcuts;
        for (int r=0; r<R; r++) {
            int rcount = 0;
            for (int c=0; c<C; c++) {
                if (w[r][c]) {
                    rcount++;
                }
            }
            choco_in_piece += rcount;
            cout << choco_in_piece << endl;
            if (choco_in_piece > cnum_r) {
                is_possible = false;
                break;
            } else if (choco_in_piece == cnum_r) {
                choco_in_piece = 0;
                rowcuts.push_back(r);
                H--;
                if (H<-1) {
                    is_possible = false;
                    break;
                }
            }
        }

        vector<int> colcuts;
        for (int c=0; c<C; c++) {
            int count = 0;
            for (int r=0; r<R; r++) {
                if (w[r][c]) {
                    count++;
                }
            }
            choco_in_piece += count;
            cout << choco_in_piece << endl;
            if (choco_in_piece > cnum_r) {
                is_possible = false;
                break;
            } else if (choco_in_piece == cnum_r) {
                choco_in_piece = 0;
                rowcuts.push_back(r);
                V--;
                if (V<-1) {
                    is_possible = false;
                    break;
                }
            }
        }


        if (!is_possible) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        if (is_possible) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}
