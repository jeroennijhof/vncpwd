/*
   VNC Password Decrypter
   Copyright (c) 2018 Jeroen Nijhof <jeroen@jeroennijhof.nl>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "d3des.h"

static u_char obfKey[8] = {23,82,107,6,35,78,88,7};

void decryptPw( unsigned char *pPW ) {
    unsigned char clrtxt[10];
	
    deskey(obfKey, DE1);
    des(pPW, clrtxt);
    clrtxt[8] = 0;

    fprintf(stdout, "Password: %s\n", clrtxt);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    unsigned char *pwd;

    if (argc < 2) {
        fprintf(stdout, "Usage: vncpwd <password file>\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: can not open password file: %s\n", argv[1]);
        return 1;
    }
    pwd = malloc(1024);
    fread(pwd, 1024, 1, fp);
    fclose(fp);

    decryptPw(pwd);

    free(pwd);
    return 0;
}
