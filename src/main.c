#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "file.h"

int main(int argc,char* argv[])
{
	if(argc==1)
	{
		printf("Can not do nothing.\nNo argument where found.\n");
		return 1;
	}
	FILE* file=fopen(argv[1],"r");
	char** src_file=NULL;
	int result=exe_IMcmake_file(file,src_file);
	if(result!=0)
		printf("ERROR line %d\n",result);
	printf("ERROR line %d\n",result);
	fclose(file);
	return 0;
}
