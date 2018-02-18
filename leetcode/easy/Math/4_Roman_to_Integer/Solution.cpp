class Solution {
public:
    int romanToInt(string s) {
        // IVXLCDM
        int num = 0;
        int prev = 1000;
        for(int i=0; i<s.size(); i++) {
            switch(s[i]) {
                case 'I':
                    num += 1;
                    prev = 1;
                    break;
                case 'V':
                    num += 5;
                    if (prev < 5)
                        num -= 2*prev;
                    prev = 5;
                    break;
                case 'X':
                    num += 10;
                    if (prev < 10) 
                        num -= 2*prev;
                    prev = 10;
                    break;
                case 'L':
                    num += 50;
                    if (prev < 50) 
                        num -= 2*prev;
                    prev = 50;                   
                    break;
                case 'C':
                    num += 100;
                    if (prev < 100) 
                        num -= 2*prev;
                    prev = 100;
                    break;   
                case 'D':
                    num += 500;
                    if (prev < 500)
                        num -= 2*prev;
                    prev = 500;
                    break;   
                case 'M':
                    num += 1000;
                    if (prev < 1000)
                        num -= 2*prev;
                    prev = 1000;
                    break;       
                default:
                    break;
            }
        }
        return num;
    }
};
