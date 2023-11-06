# build IceCode



## linux平台可能需要引入C++类库

IceKey.h

```c++
/*
 * Header file for the C++ ICE encryption class.
 *
 * Written by Matthew Kwan - July 1996
 */

#ifndef _ICEKEY_H_
#define _ICEKEY_H_

#include <stdio.h>
#include <stdlib.h>

#if defined(_MPRAS_)
   #include <strings.h>
#elif defined(_SUN_)
   #include <strings.h>
#elif defined(_LINUX_)
   #include <string.h>
#elif defined(WIN32)
   #include <string.h>
#endif

#include <cstring>  /* 这里，切记没有.h */

/* Structure of a single round subkey */

```

## build

1. 编译IceKey.cpp，得到 IceKey.o

```shell
gcc -c IceKey.cpp -I . -o IceKey.o

# 得到 IceKey.o
```

2. 编译IceCode.cpp，得到IceCode.o

```shell
gcc -c IceCode.cpp -I . -o IceCode.o

# 得到 IceCode.o
```

3. 链接得到可执行程序IceCode

```shell
g++ -o IceCode IceCode.o IceKey.o

# 得到可执行程序 IceCode

etl@TDExpress1700_Sles12:~/src/IceCode> ./IceCode 
IceCode, by Jet Wu, NCR Taiwan
Syntax: IceCode.exe -[e|d] <text> <key>

This program will encode or decode <text> with <key> in ICE algorithm.
The encoded or decoded text will output to standard out.
-e means encode data.
-d means decode data.

Syntax: IceCode.exe <logon string>

This program will decode the password in <logon string>.
The decoded logon string will output to standard out.
```

## cmake
```shell
cmake -B build -S .
cmake --build build
```



## test

```shell
# 加密
ETL> ./IceCode -e abc123 huzy
6f21fe9dcf8005a5 
# 解密
ETL> ./IceCode -d 6f21fe9dcf8005a5 huzy
abc123etl 

# 生产用文件解密
ETL> ./IceCode ".LOGON huzy,6f21fe9dcf8005a5;"
.LOGON huzy,abc123;


```

