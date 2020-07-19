int KMP(char* txt, char* pat) {
    
    int txtLen = strlen(txt);
    int patLen = strlen(pat);
    
    int i = 0;
    int j = 0;
    
    while (i < txtLen && j < patLen) {
        if (j == -1 || txt[i] == pat[j]) {
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    
    if (j == patLen) {
        return i - j;
    }
    else{
        return -1;
    }
}

void GetNext(char* pat, int& next[])
{
    int patLen = strlen(pat);
    next[0] = -1;
    int k = -1;
    int j = 0;
    
    while (j < patLen) {
        if (k == -1 || p[j] == p[k]) {
            ++k;
            ++j;
            next[j] = k;
        }
        else{
            k = next[k];
        }
    }
}