program: gauss.o backsubst.o mat_io.o main.c
	cc gauss.o backsubst.o mat_io.o main.c -o program

gauss.o: gauss.c gauss.h
	cc gauss.c -c

backsubst.o: backsubst.c backsubst.h
	cc backsbust.c -c

mat_io.o: mat_io.c mat_io.h
	cc mat_io.c -c
