# Make file
CC = g++

LIBS =
INCLUDE = -I ../include

CPPFLAGS = -g -O2 -fpermissive ${INCLUDE}

DIRS = .

SRCS = $(foreach dir, ${DIRS}, ${wildcard $(dir)/*.cc})
TARGET = ${patsubst %.cc, %, $(SRCS)}
OBJS = ${patsubst %.cc, %.o, $(SRCS)}

SERVER_TARGET = server
CLIENT_TARGET = client
SERVER_OBJS = server.o
CLIENT_OBJS = client.o

all : ${TARGET}

${SERVER_TARGET}:${SERVER_OBJS}
	${CC} ${CPPFLAGS} -o ${SERVER_TARGET} ${SERVER_OBJS}

${CLIENT_TARGET}:${CLIENT_OBJS}
	${CC} ${CPPFLAGS} -o ${CLIENT_TARGET} ${CLIENT_OBJS}

clean:
	rm -rf *.o
	rm -rf ${TARGET}
