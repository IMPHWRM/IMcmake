#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "file.h"

int exe_IMcmake_file(FILE* file,char** src_file)
{
	char CC[7];
	int line=1;
	int running=1;
	char current_char;
	while(running)
	{
		current_char=fgetc(file);
		switch(current_char)
		{
			case 35:
				while(current_char!=10)
				{
					current_char=fgetc(file);
					if(current_char==-1)
					{
						running=0;
						break;
					}
				}
				line++;
				break;
			case 83:
				//if the next character are not "RC" return the actuel line
				if(fgetc(file)==82 || fgetc(file)==67)
					return line;
				current_char=fgetc(file);
				while(current_char==32)
					current_char=fgetc(file);
				//61 mean =
				if(current_char==61)
				{
					do
					{
						current_char=fgetc(file);
						if(current_char==-1)
							return line;
						if(current_char==10)
							line++;
					}
					while(current_char==32 || current_char==10)

				}

				//91 mean [
				if(current_char==91)
				{

				}
			case -1:
				running=0;
				break;
		}
	}
	return 0;
}
int init_IMcmake()
{
	if(!manage_mkdir_error(mkdir(".IMcmake",S_IRWXU)))
		return -1;

