
#define MODE_READ 0
#define MODE_APPEND 1

#define BLOCKSIZE 4094 // bytes

int create_vdisk (char *vdiskfilename, int m);

int sfs_format (char *vdiskname); 
int sfs_mount (char *vdiskname);
int sfs_umount (); 
int sfs_create(char *filename);
int sfs_open(char *file, int mode);
int sfs_close(int fd);
int sfs_read(int fd, void *buf, int n);
int sfs_append(int fd, void *buf, int n); 
int sfs_delete(char *filename);

