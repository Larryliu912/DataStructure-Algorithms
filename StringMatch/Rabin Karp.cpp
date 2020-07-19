int RabinKarp(const string& txt, const string& pat)
{
    patHash = hash(pat);
    for (int i = 0; i < txt.size() - pat.size() + 1; ++i) {
        txtHash = hash(txt.substr(i, i + pat.size()));
        if (patHash == txtHash) {
            // verify
            if (txt.substr(i, i + pat.size()) == pat) {
                return i;
            }
        }
    }
    return -1;
}

int hash(const string& str)
{
    int PRIME_NUM = 101;
    int NUMBER = 256;
    int result = 0;
    
    for (int i = 0; i < str.size(); ++i) {
        result = (result*NUMBER + str[i])%PRIME_NUM;
    }
    
    return result;
}