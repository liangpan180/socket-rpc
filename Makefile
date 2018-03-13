# Make file
CC = g++
CFLAGS = -g -O2
INCLUDE =
LIBS =

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
	${CC} -o ${SERVER_TARGET} ${SERVER_OBJS}

${CLIENT_TARGET}:${CLIENT_OBJS}
	${CC} -o ${CLIENT_TARGET} ${CLIENT_OBJS}

clean:
	rm -rf *.o
	rm -rf ${TARGET}
