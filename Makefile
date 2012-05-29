all:
	gcc -o vncpwd vncpwd.c d3des.c

clean:
	rm vncpwd
