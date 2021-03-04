CFLAGS = -Wall -pedantic
app: main.c list.c user.c utils.c date.c file.c
	gcc ${CFLAGS} list.c user.c utils.c date.c file.c