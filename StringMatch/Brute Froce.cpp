int BruteForce(const string& txt, const string& pat) {
    
    int txtLen = txt.size();
    int patLen = pat.size();
    
    int txtP = 0;
    int patP = 0;
    
    while (txtP < txtLen && patP < patLen) {
        if (txt[txtP] == pat[patP]) {
            txtP++;
            patP++;
        }
        else{
            txtP = txtP - patP + 1;
            patP = 0;
        }
    }
    
    if (patP == patLen) {
        return txtP - patP;
    }
    else{
        return -1;
    }
}