#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define EQUAL 0
#define OK 0
#define FALSE -1
#define ERROR -1
#define OVERFLOW -2

#define MAX_STRLEN 256

typedef int Status;

typedef unsigned char SString[MAX_STRLEN];

SString T, S, Sub, S1, S2;

Status Assign(SString T, char *chars) {
    if (strlen(chars) > MAX_STRLEN) {
        return ERROR;
    }
    else {
        int i = 0;
        
        while (chars[i] != '\0') {
            T[i] = chars[i];
            i++;
        }
        T[i] = '\0';
        
        return OK;
    }
}

Status Initialize(SString T) {
    for (size_t i = 0; i < MAX_STRLEN; i++) {
        T[i] = '\0';
    }
    
    return OK;
}

Status Clear(SString T) {
    int i = 0;
    
    while (T[i] != '\0') {
        T[i] = '\0';
        i++;
    }
    
    return OK;
}

Status Destroy(SString T) {
    Clear(T);
    
    return OK;
}

int Length(SString T) {
    int i = 0;
    
    while (T[i] != '\0') {
        i++;
    }
    
    return i;
}

Status Copy(SString T, SString S) {
    int a = Length(S);
    
    if (a > MAX_STRLEN) {
        return OVERFLOW;
    }
    else {
        Clear(T);
        for (size_t i = 0; i < a; i++) {
            T[i] = S[i];
        }
        
        return OK;
    }
}

Status Copy_part(SString S, SString Sub, int pos, int len) {
    Initialize(Sub);
    
    if (pos + len < MAX_STRLEN) {
        int i, j = pos-1;
        for (i = 0; i < len; i++) {
            Sub[i] = S[j];
            j++;
        }
        return OK;
    }
    else {
        return ERROR;
    }
}

int Compare(SString T, SString S) {
    int a = Length(T);
    int b = Length(S);
    int c = a > b ? a : b;
    
    for (size_t i = 0; i < c; i++) {
        if (T[i] > S[i]) {
            return TRUE;
        }
        else if (T[i] < S[i]) {
            return FALSE;
        }
        else {
            continue;
        }
    }
    return EQUAL;
}

Status Insert(SString S, SString T, int pos) {
    int a = Length(S);
    int b = Length(T);
    
    if (a + b > MAX_STRLEN-1) {
        int c = MAX_STRLEN -1 - a;
        int i, j = 0;
        
        for (i = MAX_STRLEN-1; i >= pos; i--) {
            if (i - c < 0) {
                S[i] = '0';
            }
            else {
                S[i] = S[i-c];
            }
        }
        for (i = pos-1; i < pos-1 + c; i++) {
            S[i] = T[j];
            j++;
        }
        return FALSE;
    }
    else {
        int i, j = 0;
        for (i = a + b-1; i >= pos; i--) {
            if (i - b < 0) {
                S[i] = '0';
            }
            else {
                S[i] = S[i-b];
            }
        }
        for (i = pos-1; i < pos-1 + b; i++) {
            S[i] = T[j];
            j++;
        }
        return TRUE;
    }
}

Status Delete(SString S, int pos, int len) {
    int a = Length(S);
    if (len + pos > MAX_STRLEN) {
        int i;
        for (i = pos-1; i < MAX_STRLEN - 1; i++) {
            S[i] = '\0';
        }
        return ERROR;
    }
    else {
        int i;
        for (i = pos-1; i < a - len - 1; i++) {
            S[i] = S[i + len];
        }
        for (i = a - len - 1; i < a; i++) {
            S[i] = '\0';
        }
        return OK;
    }
}

Status SubString(SString T, SString Sub, int pos, int len) {
    Initialize(Sub);
    
    int a = Length(T);
    
    if (pos + len > a) {
        return ERROR;
    }
    else {
        int i, j = 0;
        for (i = pos-1; i < pos + len - 1; i++) {
            Sub[j] = T[i];
            j++;
        }
        return OK;
    }
}

Status Concat(SString T, SString S1, SString S2) {
    int a = Length(S1);
    int b = Length(S2);
    
    if (a + b > MAX_STRLEN) {
        Initialize(T);
        int i, j = 0;
        for (i = 0; i < a; i++) {
            T[i] = S1[i];
        }
        for (i = a; i < MAX_STRLEN; i++) {
            T[i] = S2[j];
            j++;
        }
        return ERROR;
    }
    else {
        Initialize(T);
        int i, j = 0;
        for (i = 0; i < a; i++) {
            T[i] = S1[i];
        }
        for (i = a; i < a + b; i++) {
            T[i] = S2[j];
            j++;
        }
        return OK;
    }
}

Status Traversal(SString T) {
    int letters[128];
    memset(letters, 0, sizeof(letters));
    int i = 0;
    
    while (T[i] != '\0') {
        letters[T[i] - 'A' + 65]++;
        i++;
    }
    
    for (i = 0; i < 128; i++) {
        printf("%d(%c) : %d\n", i, i, letters[i]);
    }
    
    return OK;
}

int Index(SString S, SString T) {
    int a = Length(S);
    int b = Length(T);
    if (a < b) {
        return ERROR;
    }
    else {
        int i;
        for (i = 1; i < a; i++) {
            Initialize(Sub);
            Copy_part(S, Sub, i, b);
            if (Compare(Sub, T) == 0) {
                return i;
            }
            else {
                continue;
            }
        }
    }
    return FALSE;
}

int KMP(SString S, SString T) {
    int pos = 0;
    return pos;
}

Status Replace(SString S, SString T, SString V) {
    while (Index(S, T) != -1) {
        int a = Length(T);
        int pos = Index(S, T);
        
        Delete(S, pos, a);
        Insert(S, V, pos);
    }
    return OK;
}
int main(int argc, char const *argv[]) {
    
    return 0;
}
