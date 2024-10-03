#include<stdio.h>
#include<string.h>

int is_palindrome(char s[], int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1; 
}

void longest_palindrome(char s[]) {
    int max_len = 0;
    int start_index = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (is_palindrome(s, i, j)) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                    start_index = i;
                }
            }
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start_index; i < start_index + max_len; i++) {
        putchar(s[i]);
    }
    printf("\n");
}

int main() {
    char input1[] = "babad";
    printf("Input: %s\n", input1);
    longest_palindrome(input1);

    char input2[] = "cbbd";
    printf("Input: %s\n", input2);
    longest_palindrome(input2);

    char input3[] = "a";
    printf("Input: %s\n", input3);
    longest_palindrome(input3);

    return 0;
}
