#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pwd.h>
#include<unistd.h>

typedef unsigned int role;

struct urentry{
	uid_t uid;
	role r;
};
urentry ur[100] = {{0,91}, {1,92}, {2,93}};

struct rpentry{
	role r;
	char prive[5];
};
rpentry rp[100] = {{91, "rwx"}, {92, "r--"}, {93, "---"}};

int main()
{
	uid_t uid;
	uid = getuid();
	
	role role_fetch = 0;

	char prive_fetch[5] = {'0'}; 

	urentry *p = ur;
	while(p++)
		if(p.uid == uid)
			role_fetch = p.r; 
	if(!role_fetch)
	{
		p.uid = uid;
		p.r = 93;
		printf("CAN'T FIND UID\n");
		goto exit;
	}	

	rpentry *q = rp;
	while(q++)
		if(q.r==role_fetch)
			prive_fetch = p.prive;

    if(prive_fetch[0] == '0')
    {
		printf("CAN'T FIND ROLE");
		goto exit;
    }
   	
   	if(prive_fetch[0]=='r'){
    	printf(" I am system call!\n");
    	goto exit;
    }
    
    printf("NO PERMISSION\n");

exit:
    return 0;
}



