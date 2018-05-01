#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T, D;
    string P;
    int count, total_dmg, curr_dmg;
    vector<int> charges;

    cin >> T;
    for (int t=0; t<T; t++) {
        count = 0;
        total_dmg = 0;
        curr_dmg = 1;
        charges.clear();

        cin >> D >> P;
        cout << "Case #" << t+1 << ": ";

        for (int i=0; i<P.size(); i++) {
            if (P[i] == 'C') {
                curr_dmg *= 2;
                charges.push_back(i);
            } else {
                total_dmg += curr_dmg;
            }
        }
        
        // in minimum damage case
        if (P.size() - charges.size() > D) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // Definitely possible
        int last_idx = charges.size()-1;
        int stacked_c = 0;
        while (1) {
            //cout << "last index: " << last_idx << '\n';
            //cout << "last charge position: " << charges[last_idx] << '\n';
            //cout << "total_dmg: " << total_dmg << '\n';
            //cout << "curr_dmg: " << curr_dmg << '\n';

            if (total_dmg <= D) {
                cout << count << '\n';
                break;
            }

            if (charges[last_idx] < P.size() - 1 - stacked_c) {
                total_dmg -= curr_dmg/2;
                charges[last_idx]++;
                count++;
            } else {
                curr_dmg /= 2;
                last_idx--;
                stacked_c++;
            }
        }
    }
}
