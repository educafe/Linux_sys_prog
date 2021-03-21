#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){
	FILE *fp;
	int i;
	char data[8]={0,};	
	if((fp = fopen(argv[1], "r")) == NULL){
		perror("fopen");
		exit(1);
	}
	memset(data, 0, sizeof(data)); 
	while(1) {
		fread(data, sizeof(data),1, fp);
		puts(data);
		if (feof(fp)) {
			break;
		}
		memset(data, 0, sizeof(data));  
	}
	fclose(fp);
	return 0;
					
}
