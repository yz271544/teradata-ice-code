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

/* Structure of a single round subkey */
class IceSubkey {
public:
    unsigned long val[3];
};

class IceKey {
public:
    IceKey(int level);
    ~IceKey();

// method
public:
    void set(const unsigned char *key);

    void	encrypt(const unsigned char *plaintext, unsigned char *ciphertext);
    void	decrypt(const unsigned char *ciphertext, unsigned char *plaintext);

    void	encode(unsigned char* data, unsigned char* k, char* output);
    void	decode(unsigned char* data, unsigned char* k, char* output);

    int keySize(void);
    int blockSize(void);

private:
    void scheduleBuild (unsigned short *k, int n, const int *keyrot);

    void ice_sboxes_init(void);
    unsigned int gf_mult(unsigned int a, unsigned int b, unsigned int m);
    unsigned long gf_exp7(register unsigned int	b, unsigned int m);
    unsigned long ice_perm32(unsigned long x);
    unsigned long ice_f(unsigned long p, const IceSubkey *sk);

// member variable
public:
    static const unsigned long ice_pbox[32];
    static const int ice_smod[4][4];
    static const int ice_sxor[4][4];
    static const int ice_keyrot[16];

private:
    int _size;
    int _rounds;
    IceSubkey *_keysched;
};

#endif
