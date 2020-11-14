/*
 * In a string, a "run" is a substring with consisting of consecutive
occurrences of the same character. For example, the string
"mississippi" contains the following runs - "ss", "ss" and "pp".

In this question, given a string, you have to output the length of the
longest run in the string.

Input
-----
A string, having length at most 100. The string is guaranteed to have
at least one run.

Output
------
The length of the longest run in the string.

Sample Input
------------
abbaaacccc

Sample Output
-------------
4
* */

#include<stdio.h>
#include<string.h>

#define max(a, b) a > b ? a : b

int solve(char *a) {
	int max_len = 0;
	int curr_len = 0;
	char curr_char;
	for(int i = 0; *(a + i) != '\0'; i++){
		curr_char = *(a + i);
		curr_len = 0;
		while(*(a + i) == curr_char && *(a + i) != '\0') {
			i++;
			curr_len++;
		}
		i--;
		max_len = max(curr_len, max_len);
	}
	return max_len;
}
int main() {
	char a[100];
	scanf("%s", a);
	printf("%d", solve(a));
	return 0;
}
