


all: libsimplefs.a app

libsimplefs.a: 	simplefs.c
	gcc -Wall -c simplefs.c
	ar -cvq libsimplefs.a simplefs.o
	ranlib libsimplefs.a

app: 	app.c
	gcc -Wall -o app app.c  -L. -lsimplefs

clean: 
	rm -fr *.o *.a *~ a.out app  vdisk1.bin
