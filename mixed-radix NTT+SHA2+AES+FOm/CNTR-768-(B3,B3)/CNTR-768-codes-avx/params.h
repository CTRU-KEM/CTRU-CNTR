#ifndef PARAMS_H
#define PARAMS_H

#ifndef CTRU_ALPHA
#define CTRU_ALPHA 3
#endif

#define CTRU_Q 3457
#define CTRU_LOGQ 12
#define CTRU_Q2 1024  /* Change this for the ciphertext modulus */
#define CTRU_LOGQ2 10 /* Change this for the ciphertext modulus */

#define CTRU_N 768
#define CTRU_NTT_N 256
#define CTRU_BOUND 7
#define CTRU_COIN_BYTES (CTRU_N * 3 / 2)

#define CTRU_SEEDBYTES 32
#define CTRU_SHAREDKEYBYTES 32
#define CTRU_MSGBYTES (CTRU_N / 16)

#define CTRU_PKE_PUBLICKEYBYTES (CTRU_LOGQ * CTRU_N / 8)
#define CTRU_PKE_CIPHERTEXTBYTES (CTRU_LOGQ2 * CTRU_N / 8)
#define CTRU_PKE_SECRETKEYBYTES (4 * CTRU_N / 8)

#define CTRU_KEM_PUBLICKEYBYTES CTRU_PKE_PUBLICKEYBYTES
#define CTRU_KEM_SECRETKEYBYTES (CTRU_PKE_SECRETKEYBYTES + CTRU_PKE_PUBLICKEYBYTES)
#define CTRU_KEM_CIPHERTEXTBYTES CTRU_PKE_CIPHERTEXTBYTES
#define CTRU_PREFIXHASHBYTES 33

#endif