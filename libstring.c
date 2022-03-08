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


// Return number of chars at beginning of s which are in c
size_t strspn(const char *s, const char *c) {
    // Lookup table for all chars of c
    char lu[256] = {0};
    for (; *c; lu[(int) *c] = 1, c++) {;}

    // Iterate through s as long as chars are element of c and count
    size_t ctr = 0;
    for (; *s && lu[(int) *s]; ctr++, s++) {;}
    return ctr;
}


// Return number of chars at beginning of s which are all not in c
size_t strcspn(const char *s, const char *c) {
    // Lookup table for all chars of c
    char lu[256] = {0};
    for (; *c; lu[(int) *c] = 1, c++) {;}

    // Iterate through s as long as chars are not element of c and count
    size_t ctr = 0;
    for (; *s && !lu[(int) *s]; ctr++, s++) {;}
    return ctr;
}


// Return pointer to first char in s that is not part of c
char *strpbrk(const char *s, const char *c) {
    // Lookup table for all chars of c
    char lu[256] = {0};
    for (; *c; lu[(int) *c] = 1, c++) {;}

    // Iterate through s as long as chars are not element of c
    for (; *s && !lu[(int) *s]; s++) {;}
    return s;
}


// TODO Return pointer to first occurence of t in s
// char *strstr(const char *s, const char *t)


// TODO Return pointer to string describing error number n
// char *strerror(int n) {}


// TODO Tokenise string s with all chars from c as delimiters
// char *strtok(char *s, const char* c)


// Copy n symbols from t to s, return s
void *memcpy(void *s, const void *t, size_t n) {
    char *u = (char*) s;
    char *v = (char*) t;
    for (; n--; *u++ = *v++) {;}
    return (void*) u;
}


// Same as memcpy, but also works if s,t overlap
void *memmove(void *s, const void *t, size_t n) {
    if (s > t) {
        // Source starts after destination - forward copy
        memcpy(s, t, n);
    } else {
        // Else backwards copy
        char *u = (char*) s;
        char *v = (char*) t;
        for (int i = (int) n; i > 0; i--) {
            u[i-1] = v[i-1];
        }
    }
    return s;
}

// TODO
// int memcmp(cs,ct,n)
// void *memchr(cs,c,n)
// void *memset(s,c,n)

// Some testing
int main() {
    char str1[] = "abcxxxxxxxxx";
    char str2[] = "123456789abcdef";
    printf("%i\n", (int) strspn(str1, str2));

    char str3[] = "ghijkl1234";
    char str4[] = "123456789abcdef";
    printf("%i\n", (int) strcspn(str3, str4));
    printf("%c\n", *strpbrk(str3, str4));


    return 0;

}
