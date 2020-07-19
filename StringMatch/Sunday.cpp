class Solution {
public:

    int strStr(const string& txt, const string& pat)
    {
        
        int txtLen = txt.size();
        int patLen = pat.size();
        
        if (patLen == 0) {
            return 0;
        }
        
        int txtP = 0;
        int patP = 0;

        int move[256];

        GenerateMove(move, pat);

        while (txtP <= txtLen - patLen) {
            patP = 0;
            while (txt[txtP + patP] == pat[patP]) {
                patP++;
                if (patP == patLen) {
                    return txtP;
                }
            }
            txtP += move[txt[txtP + patLen]];
        }
        return -1;
    }

    void GenerateMove(int& move[256], const string& pat)
    {
        int patLen = pat.size();
        for (int i = 0; i < 256; ++i) {
            move[i] = patLen + 1;
        }
        for (int i = 0; i < patLen; ++i) {
            move[pat[i]] = patLen - i;
        }
    }

};