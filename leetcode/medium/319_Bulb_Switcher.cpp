class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 0) return 0;
        // ith bulb는 i의 약수의 갯수만큼 toggle된다. 약수의 갯수가 홀수이면 on으로 끝나므로 그런 i의 갯수를 세면 된다.
        // 약수의 갯수가 홀수이려면, 각 인수의 갯수가 모두 짝수여야 한다 --> 제곱수여야 한다. 따라서 n보다 작은 제곱수의 갯수를 구하면 된다.
        return sqrt(n);
    }
};
