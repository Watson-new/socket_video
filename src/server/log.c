#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int log_store_to_file(char *string, const char *filepath, const char *function, const int line)
{
	char *ptr = NULL;
	ptr = (char*)malloc(sizeof(char)*1024);//malloc
	if (ptr == NULL || string == NULL){
		free(ptr);
		return -1;
	}
	else{
		sprintf(ptr,"echo string:[%s] filepath:[%s] function:[%s] line:[%d] >> ../logfile/store.log",string,filepath,function,line);
	}	
	if (-1 == system(ptr)){
		free(ptr);
		return -1;
	}
	printf("The ptr is %s\n",ptr);
	free(ptr);//free
	ptr = NULL;

	return 0;
}


