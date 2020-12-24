#include <stdio.h>

int main()
{
	int d = getchar()-'t';
	putchar('t');
	
	for(int i = 1; i < 100; i++){
		int c=getchar();
		if(c == '#'){
			break;
		}
		putchar('a'+((c-'a'-d)%26));
	}

	return 0;
}