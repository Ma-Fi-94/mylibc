#include <stdio.h>

// Copy s to d; return d.
char *strcpy(char *d, const char *s) {
    char *ret = d;
    while ((*d++ = *s++)) {;}
    return ret;
}


// Copy at most n chars from s to d,
// Pad d with \0, if s is shorter than n.
// Return d.
char *strncpy(char *d, const char *s, size_t n) {
    char *ret = d;
    while (n--) {
        if ((*d++ = *s++) == 0) {
            while (--n) {*d++ = 0;}
        }
    }
    return ret;
}


// Append s to d, return d.
char *strcat(char* d, const char* s) {
    char *ret = d;
    while (*++d) {;} // stop on the \0
    while ((*d++ = *s++)) {;} // copy all including the \0
    return ret;
}


// Append at most n characters from s to d,
// afterwards, append \0 if required and return d.
// NB: Unlike strncpy, we don't guarantee to copy n chars.
char *strncat(char *d, const char* s, size_t n) {
    char *ret = d;
    while (*++d) {;} // stop on the \0
    while (n-- && (*d++ = *s++)) {;}
    if (*d) {*d=0;} // add terminal \0 if required
    return ret;
}


// Get length of string s without terminal \0.
size_t strlen(const char *s) {
    size_t n = 0;
    while (*s++) {n++;}
    return n;
}


// Compare strings s and t
// Return <0 if cs<ct; 0 if cs==ct, >0 if cs>ct.
int strcmp(const char *s, const char *t) {
    // Cannot use increment in loop head,
    // we would skip the first char (pre-incr.),
    // or land on \0 (post-increment).
    while (*s && *s == *t) {s++; t++;}
    return *s - *t;
}

// Compare at most n chars of s and t
// Return <0 if cs<ct; 0 if cs==ct, >0 if cs>ct.
int strncmp(const char* s, const char *t, size_t n) {
    while (*s && *s == *t && --n) {s++; t++;}
    return *s - *t;
}


// Return ptr to first c in s, or NULL if not present
char *strchr(const char *s, int c) {
    while(*s != c && *s++) {;}
    return (*s ? s : NULL);
}


// Return ptr to last c in s, or NULL if not present
char *strrchr(const char *s, int c) {
    char *r = NULL;
    for (; *s; s++) {
        if (*s == c) {r = s;}
    }
    return r;
}


// Some testing
int main() {
    char str1[] = "This is a test";
    printf("%li\n", strchr(str1, 'a') - str1);
    printf("%li\n", strchr(str1, 'i') - str1);
    printf("%p\n", strchr(str1, 'z'));

    printf("%li\n", strrchr(str1, 'a') - str1);
    printf("%li\n", strrchr(str1, 'i') - str1);
    printf("%p\n", strrchr(str1, 'z'));


    return 0;

}
