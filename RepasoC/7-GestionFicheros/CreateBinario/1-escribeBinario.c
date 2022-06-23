#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE	512

struct _tipo_{
	double b;
	int a;
	char c[10];
	short d;
} var;
 
int main(int argc, char **argv) {
	
	FILE *sal;
	char * nomFich = "datos.txt";
	int x = 7, y = 8; 	 
	int i;
	var.a = 10;
	var.b = 1.25;
	var.c[0]='H';
	var.c[1]='i';
	var.c[2]='!';
	var.d = 17;
 
	for (i=3;i<10;i++) var.c[i] = 0;
   	
	// Escritura, lectura y/o creación.
    sal = fopen(nomFich, "w+");
    	
	if (sal == NULL){
        perror("creat has failed");    
		exit(-1);
    }	   

	// Escritura en bianrio.
	if (fwrite(&x, sizeof(int), 1, sal) < 1) { 
    	perror("write has failed");
		fclose(sal);
        exit(-1);
    }
	 
	 if (fwrite(&y, sizeof(int), 1, sal) < 1)  {
        perror("write");
		fclose(sal);
        exit(-1);
	}

	 if (fwrite(&var, sizeof(var), 1, sal) < 1)  {
        perror("write");
		fclose(sal);
        exit(-1);
	}
    
	fclose(sal);
    exit(0);

}
