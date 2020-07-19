class Solution {
public:
int strStr(string txt, string pat)
{
    int txtLen = txt.size();
    int patLen = pat.size();
    
    if (patLen == 0) {
        return 0;
    }
    
    int badCharMove[256];
    GenerateBadCharMove(pat, badCharMove);
    int suffix[patLen];
    int prefix[patLen];
    GenerateGoodSuffix(pat, patLen, suffix, prefix);
    int txtP = 0;
    
    while (txtP <= (txtLen - patLen)) 
    {
        int patP = patLen - 1;
        while (txt[txtP + patP] == pat[patP]) {
            patP--;
            if (patP < 0) {
                return txtP;
            }
        }
        
        int badCharMoveSteps = patP - badCharMove[txt[txtP + patP]];
		int goodSuffixMoveSteps = 0;
        if (patP < patLen - 1) {
            goodSuffixMoveSteps = GetGoodSuffixMoveSteps(patP, patLen, suffix, prefix);
        }
        
        txtP += max(badCharMoveSteps, goodSuffixMoveSteps);
    }
    return -1;
}

void GenerateBadCharMove(const string& pat, int (&badCharMove)[256])
{
    for (int i = 0; i < 256; ++i)
    {
    	badCharMove[i] = -1;    
    }
    for (int i = 0; i < pat.size(); ++i) {
        // Find the far right char, so we keep update if we meet the same char
        badCharMove[pat[i]] = i;
    }
}

void GenerateGoodSuffix(const string& pat, int patLen, int suffix[], int prefix[]) {
    // Initialize
    for (int i = 0; i < patLen; ++i) {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for (int i = 0; i < patLen - 1; ++i) {
        int j = i;
        int k = 0;
        // Found good suffix, each time search from end
        while (j >= 0 && pat[j] == pat[patLen - 1 - k]) {
            --j;
            ++k;
            suffix[k] = j + 1;
        }
        // If j == -1, that means this substring is also the prefix
        if (j == -1) {
            prefix[k] = true;
        }
    }
}

int GetGoodSuffixMoveSteps(int patP, int patLen, int suffix[], int prefix[]){
    int k = patLen - patP - 1;
    // search good suffix
    if (suffix[k] != -1) {
        return patP - suffix[k] + 1;
    }
    // Searching prefix for suffix
    // +2 because, we have suffix as k = patLen - patP - 1, so we only search from (patLen - patP - 2) --> (patLen - patP - 3) --> (patLen - patP - 4) --> ...
    for (int r = patP + 2; r <= patLen - 1; ++r) {
        // If it is true, means it is a good prefix
    	if (prefix[patLen - r] == true) {
            return r;
        }
    }
    return patLen;
}

};