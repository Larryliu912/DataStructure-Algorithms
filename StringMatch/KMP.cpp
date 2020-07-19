int KMP(const string& txt, const string& pat) {
    
    int txtLen = txt.size();
    int patLen = pat.size();
    
    if (patLen == 0) {
        return 0;
    }
    
    int next[patLen];
    GetNext(pat, next);
    
    int txtP = 0;
    int patP = 0;
    
    while (txtP < txtLen && patP < patLen) {
        if (patP == -1 || txt[txtP] == pat[patP]) {
            ++txtP;
            ++patP;
        }
        else{
            patP = next[patP];
        }
    }
    
    if (patP == patLen) {
        return txtP - patP;
    }
    else{
        return -1;
    }
}

void GetNext(const string& pat, int next[])
{
    int patLen = pat.size();
    next[0] = -1;
    int k = -1;
    int patP = 0;
    
    while (patP < patLen - 1) {
        if (k == -1 || pat[patP] == pat[k]) {
            ++k;
            ++patP;
            next[patP] = k;
        }
        else{
            k = next[k];
        }
    }
}