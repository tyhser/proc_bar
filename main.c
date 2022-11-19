#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void proc_bar(int x)
{
        char buf[301];
        int i = 0;
        char index[6] = "-\\|/\0";
	int w;
	memset(buf, '\0', 300);

	if (x > 100 || x < 0)
		return;
        while (i <= x*3) {
		buf[i] = 0xe2;
		buf[i+1] = 0x96;
		buf[i+2] = 0x89;
                printf("[%c][%-*s][%d%%]\r", index[i % 4], 103+(i/3)*2, buf, i/3);
                i+=3;
        }
        fflush(stdout);
}

int main(void)
{
	for (int i = 0; i <= 100; i++) {
        	proc_bar(i);
		//printf("\r");
		usleep(100000);
	}

        printf("\n");
}
