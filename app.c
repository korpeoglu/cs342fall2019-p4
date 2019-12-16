


#include <stdio.h>
#include <stdlib.h>

#include "simplefs.h"

#define DISKNAME "vdisk1.bin"

int main()
{
    int x;
    
    printf ("started\n"); 
    
    x = create_vdisk (DISKNAME, 20); 
    printf ("%d", x); 

    sfs_mount (DISKNAME); 
    
    sfs_umount(); 
}
