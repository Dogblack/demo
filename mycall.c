#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pwd.h>
#include<unistd.h>

typedef unsigned int role;

int main()
{
	uid_t uid;
	uid = getuid();
	uid_t uid_match;
	role role_fetch;
	role role_match;
	char prive_fetch[5]; 

	FILE *fp = popen("cat uid_role", "r");

	while(!feof(fp)){	
		fgets((char *)&uid_match,sizeof(uid_match),fp);
		fgets((char *)&role_fetch,sizeof(2*sizeof(role)),fp);
		
		if(uid_match==uid)
            		goto Role2Prive;
	}        
	printf("CAN'T FIND UID\n");
   	return 0;

   Role2Prive:
	fp = popen("cat role_prive", "r");    
	while(!feof(fp)){	
		fgets((char *)&role_match,sizeof(role_match),fp);
		fgets((char *)prive_fetch,sizeof(prive_fetch),fp);

		if(role_match==role_fetch)
	    	        goto Mycall;
	}  
   
	printf("CAN'T FIND ROLE");
   	return 0;

   Mycall:
    if(prive_fetch[0]=='r'){
    	printf(" I am system call!\n");
    	return 0;
    }
      printf("NO PERMISSION\n");
      return 0;
}




