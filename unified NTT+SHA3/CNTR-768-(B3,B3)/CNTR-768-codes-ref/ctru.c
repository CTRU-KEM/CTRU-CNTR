#include "params.h"
#include "poly.h"
#include "pack.h"
#include <stdio.h>

int ctru_keygen(unsigned char pk[CTRU_PKE_PUBLICKEYBYTES],
                unsigned char sk[CTRU_PKE_SECRETKEYBYTES],
                const unsigned char coins[CTRU_COIN_BYTES])
{
  int r;
  poly f, fhat, g, hhat, tmp;

  poly_sample(&f, coins);
  poly_sample(&g, coins + CTRU_COIN_BYTES / 2);

  poly_double(&f, &f);
  f.coeffs[0] += 1;

  poly_split(&tmp, &f);
  poly_split(&g, &g);

  poly_ntt(&fhat, &tmp);
  poly_ntt(&g, &g);

  poly_combine(&fhat, &fhat);
  poly_combine(&g, &g);

  poly_freeze(&fhat);
  poly_reduce(&g);
  r = poly_baseinv(&tmp, &fhat);
  poly_basemul(&hhat, &g, &tmp);
  poly_freeze(&hhat);

  pack_pk(pk, &hhat);
  pack_sk(sk, &f);

  return r;
}

void ctru_enc(unsigned char ct[CTRU_PKE_CIPHERTEXTBYTES],
              const unsigned char pk[CTRU_PKE_PUBLICKEYBYTES],
              const unsigned char m[CTRU_MSGBYTES],
              const unsigned char coins[CTRU_COIN_BYTES / 2])
{

  poly r, sigma, c, hhat;

  unpack_pk(&hhat, pk);

  poly_sample(&r, coins);
  poly_split(&r, &r);
  poly_ntt(&r, &r);
  poly_combine(&r, &r);
  poly_reduce(&r);

  poly_basemul(&sigma, &hhat, &r);
  poly_frommont(&sigma);

  poly_split(&sigma, &sigma);
  poly_invntt(&sigma, &sigma);
  poly_combine(&sigma, &sigma);

  poly_freeze(&sigma);

  poly_encode_compress(&c, &sigma, m);
  pack_ct(ct, &c);
}

void ctru_dec(unsigned char m[CTRU_MSGBYTES],
              const unsigned char ct[CTRU_PKE_CIPHERTEXTBYTES],
              const unsigned char sk[CTRU_PKE_SECRETKEYBYTES])
{
  poly c, f;

  unpack_ct(&c, ct);

  unpack_sk(&f, sk);

  poly_decode(m, &c, &f);
}
