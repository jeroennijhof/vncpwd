CFLAGS = -g
PREFIX = /usr
BINDIR = ${PREFIX}/bin

all:
	gcc ${CFLAGS} -o vncpwd vncpwd.c d3des.c

install:
	install -D -m 755 vncpwd ${DESTDIR}${BINDIR}/

clean:
	rm vncpwd
