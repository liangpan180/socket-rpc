# Make file
CC = g++

LIBS =
INCLUDE = -I../include -I../base

CPPFLAGS = -g -O2 -fpermissive ${INCLUDE}

DIRS = .

SRCS = $(foreach dir, ${DIRS}, ${wildcard $(dir)/*.cc})

LIBDIR = -L../base
LDLIBS = -lBaselib
LDFLAGS = ${LIBDIR} ${LDLIBS}

SERVER_TARGET = server
CLIENT_TARGET = client
SERVER_OBJS = server.o io.o
CLIENT_OBJS = client.o io.o

all : ${SERVER_TARGET} ${CLIENT_TARGET}

${SERVER_TARGET}:${SERVER_OBJS}
	${CC} ${CPPFLAGS} -o $@ ${SERVER_OBJS} ${LDFLAGS}
 
${CLIENT_TARGET}:${CLIENT_OBJS}
	${CC} ${CPPFLAGS} -o $@ ${CLIENT_OBJS} ${LDFLAGS}

clean:
	rm -rf *.o
	rm -rf ${TARGET}
