#include <string.h>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int kmp(char t[], char p[]) {
    /*
    * move = match number - `next' value of last matched character
    * prefix = combination from the frist character to the last but one.
    * suffix = combination from the second character to the last
    * `next' value = max length of prefix and suffix for the substring of the pattern string.
    */
    if (!t || !p) {
        return -1;
    }
    const int N = strlen(p);
    const int M = strlen(t);
    int next[N + 1] = {};

    next[0] = -1; /* init */
    int pos = 1;  /* the current position we are computing in next */
    int cnd = 0;  /* the zero-based index in p of the next character of the current candidate substring */
    while (pos < N) {
        if (p[pos] == p[cnd]) {
            next[pos] = next[cnd];
        } else {
            next[pos] = cnd;
            cnd = next[cnd];
            while (cnd >= 0 && p[pos] != p[cnd]) {
                cnd = next[cnd];
            }
        }
        pos++;
        cnd++;
    }
    next[pos] = cnd;

    /* start */
    int t_ptr = 0;
    int p_ptr = 0;
    int np = 0;
    while (t_ptr < M) {
        if (p[p_ptr] == t[t_ptr]) {
            p_ptr++;
            t_ptr++;
            if (p_ptr == N) {
                p[np] = t_ptr - p_ptr;
                np++;
                p_ptr = next[p_ptr];
            }
        } else {
            p_ptr = next[p_ptr];
            if (p_ptr < 0) {
                t_ptr++;
                p_ptr++;
            }
        }
    }
    return np;
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

