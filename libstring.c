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

// Some testing
int main() {
    char str1[] = "This is ";
    char str2[] = "a test.";
    char str3[80];
    strcpy(str3, str1);
    strcat(str3, str2);
    printf("%s\n", str3);

    strcpy (str3, "This");
    strncat (str3, " is a super long string but we will only copy a few chars of it.", 3);
    printf("%s\n", str3);


   char s1[] = "abcd", s2[] = "abCd", s3[] = "abc";
   int result;

   // comparing strings str1 and str2
   result = strcmp(s1, s1);
   printf("strcmp(str1, str1) = %d\n", result);

   result = strcmp(s1, s2);
   printf("strcmp(str1, str2) = %d\n", result);

   // comparing strings str1 and str3
   result = strcmp(s1, s3);
   printf("strcmp(str1, str3) = %d\n", result);

   result = strncmp(s1, s2, 1);
   printf("strncmp(str1, str2, 1) = %d\n", result);

   result = strncmp(s1, s2, 2);
   printf("strncmp(str1, str2, 2) = %d\n", result);

   result = strncmp(s1, s2, 3);
   printf("strncmp(str1, str1, 3) = %d\n", result);

    return 0;

}
