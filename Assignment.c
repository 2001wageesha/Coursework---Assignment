#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int minPalindromeAppends(char *str) {
    int len = strlen(str);
    int i, j;
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            break;
    }

    if (i >= j)
        return 0;

    int minAppends = 0;

    for (i = len - 1; i >= 0; i--) {
        if (isPalindrome(str, 0, i))
            break;
        minAppends++;
    }

    return minAppends;
}

int main() {
    char str[100];
    scanf("%s", str);

    int minAppends = minPalindromeAppends(str);
    printf("%d\n", minAppends);

    return 0;
}
