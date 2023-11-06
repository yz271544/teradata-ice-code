
#include <stdio.h>
#include <cstring>
#include "../include/IceKey.h"

// charles

unsigned char KEY[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned char BUF[9];

void printSyntax(void)
{
    printf("IceCode, by Jet Wu, NCR Taiwan\n");
    printf("Syntax: IceCode.exe -[e|d] <text> <key>\n");
    printf("\n");
    printf("This program will encode or decode <text> with <key> in ICE algorithm.\n");
    printf("The encoded or decoded text will output to standard out.\n");
    printf("-e means encode data.\n");
    printf("-d means decode data.\n\n");

    printf("Syntax: IceCode.exe <logon string>\n");
    printf("\n");
    printf("This program will decode the password in <logon string>.\n");
    printf("The decoded logon string will output to standard out.\n");
}

char* ignoreSpace(char* p)
{
    while(1) {
        if (*p != ' ' && *p != '\t')
            return p;
        else if (*p == '\0')
            return (char*)0;
        else
            p++;
    }
}

char* moveToSpace(char* p)
{
    while(1) {
        if (*p == ' ' || *p == '\t')
            return p;
        else if (*p == '\0')
            return (char*)0;
        else
            p++;
    }
}

char* copyWord(char* p, char* t)
{
    while(1) {
        if (*p == ' ' || *p == '\t' || *p == ',' || *p == ';') {
            *t = '\0';
            return p;
        }
        else if (*p == '\0') {
            *t = '\0';
            return (char*)0;
        }
        else {
            *t = *p;
            t++; p++;
        }
    }
}

int syntax2(IceKey* ice, char *logonstr)
{
    unsigned char userid[80], password[256], buf[256], headstr[80];
    char *p;

    p = copyWord(logonstr, (char*)headstr);

    p = copyWord(logonstr+strlen(".LOGON "), (char*)userid);
    p = copyWord(p+1, (char*)password);
    ice->decode(password, userid, (char*)buf);
    printf("%s %s,%s;\n", headstr, userid,buf);
    return 0;
}

int syntax1(IceKey* ice, char* tag, char* text, char* key)
{
    char buf[256];

    if (strcmp(tag, "-e")==0) {
        ice->encode((unsigned char*)text, (unsigned char*)key, buf);
    } else if (strcmp(tag, "-d")==0) {
        ice->decode((unsigned char*)text, (unsigned char*)key, buf);
    }

    printf("%s", buf);

    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2 && argc != 4) {
        printSyntax();
        return 1;
    }

    IceKey *ice ;
    ice = new IceKey(0);

    if (argc == 4) {
        if (strcmp(argv[1], "-e")!=0 && strcmp(argv[1], "-d")!=0)
            return 2;

        syntax1(ice, argv[1], argv[2], argv[3]);
    } else {
        syntax2(ice, argv[1]);
    }

    return 0;
}
