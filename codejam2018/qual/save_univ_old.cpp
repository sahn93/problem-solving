#include <iostream>
#include <string>

using namespace std;

int main() {
    int T, D;
    string P;
    int count, scount, currdmg, totaldmg;
    bool impossible;

    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> D >> P;
        cout << "Case #" << t+1 << ": ";
        count = 0;
        scount = 0;
        totaldmg = 0;
        currdmg = 1;
        for (int i=0; i<P.size(); i++) {
            if (P[i] == 'S') {
                scount++;
                totaldmg += currdmg;
            } else if (P[i] == 'C') {
                currdmg *= 2;
            }
        }
        
        if (scount > D) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        //cout << totaldmg << " totaldmg!!!!\n";
        //cout << D << " D!!\n";
        //cout << currdmg << " currdmg!!!!\n";

        if (totaldmg <= D) {
            cout << count << '\n';
            continue;
        }

        for (int i=P.size()-1; i>0; i--) {
            //cout << i << " pos \n";

            if (P[i-1] == 'C' && P[i] == 'S') {
                // swap
                P[i-1] = 'S';
                P[i] = 'C';

                if (i==P.size()-1) i++;
                else i += 2;
                totaldmg -= (currdmg/2);
                count++;
                //cout << totaldmg << " totaldmg\n";
                //cout << currdmg << " currdmg!!!!\n";
                //cout << "SWAP!! \n";
                //cout << P << '\n';

                if (totaldmg <= D) {
                    cout << count << '\n';
                    break;
                }
            } else if (P[i] == 'C') {
                currdmg /= 2;
            }
        }
    }
}
