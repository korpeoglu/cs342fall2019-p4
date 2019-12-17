#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "simplefs.h"

#define DISKNAME "vdisk1.bin"

int main()
{
    int ret;
    int fd1, fd2;
    int i; 
    char buffer[1024];
    
    printf ("started\n"); 
    

    // ****************************************************
    // if this is the first running of app, we can
    // create a virtual disk and format it as below
    ret  = create_vdisk (DISKNAME, 24); // size = 16 MB
    if (ret != 0) {
	printf ("there was an error in creating the disk\n");
	exit(1); 
    }
    ret = sfs_format (DISKNAME);
    if (ret != 0) {
	printf ("there was an error in format\n");
	exit(1); 
    }
    // ****************************************************

    ret = sfs_mount (DISKNAME); 
    if (ret != 0) {
	printf ("could not mount \n");
	exit (1); 
    }

    sfs_create ("file1.bin");
    sfs_create ("file2.bin");
    sfs_create ("file3.bin");

    fd1 = sfs_open ("file1.bin", MODE_APPEND);
    fd2 = sfs_open ("file2.bin", MODE_APPEND); 
    for (i = 0; i < 10000; ++i) {
	buffer[0] =   (char) 65;  
	sfs_append (fd1, (void *) buffer, 1);
    }

    for (i = 0; i < 10000; ++i) {
	buffer[0] = (char) 70;
	buffer[1] = (char) 71;
	buffer[2] = (char) 72;
	buffer[3] = (char) 73;
	sfs_append(fd2, (void *) buffer, 4);
    }
    
    sfs_close(fd1); 
    sfs_close(fd2); 
    
    ret = sfs_umount(); 
}
