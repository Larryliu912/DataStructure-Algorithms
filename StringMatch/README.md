# Explanation

## Brute Force

### Code

~~~c++
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
~~~

### Explanation

The brute force idea is very straightforward. 

1. Match from the head to tail

2. If match, keep moving the two pointers

3. if mismatch, move the txt by one

   ![img](https://img-blog.csdn.net/20140723224710203)

   ![img](https://img-blog.csdn.net/20140726213551553)

   Obviously, it is slow.

   TC: `O(mn)`, m is text length, n is pattern size

## KMP

### Code

~~~c++
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
~~~

### Explanation

Main processing:

1. if patP(pattern pointer) = -1 or match, moving two pointers

2. if patP != -1 and mismatch, keep txtP, let patP = next[patP], which means when mismatch, patP move right by patP - next[patP]

   ![img](https://img-blog.csdn.net/20140726213353687)

   ![img](https://img-blog.csdn.net/20140721223539765)

Why the main algorithm works? Why we never change `i` ?

Because we have `next[patP]` here, the `next[patP]` means, for current matched string, we have `next[patP]` same suffix substring as prefix, we know that, if text can be matched by the prefix, it can also be matched by the suffix. Thus, we can shift pattern to a position which already matched prefix, because we can 'switch' the prefix and suffix. A little bit greedy thought.

In other words, from next, we find the longest prefix == suffix for current string, if we found no match, switch prefix to be the suffix, that means shift to left for the length of the prefix. That is shifting left `patP - next[patP]` or `patP  = patP - patP + next[patP] = next[patP]`.





## BM



## Sunday



## Rabin Karp