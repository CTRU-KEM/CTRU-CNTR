CC ?= /usr/bin/cc
CFLAGS += -Wall -march=native -mtune=native -O3 -fomit-frame-pointer -Wno-unknown-pragmas
LDFLAGS += -lcrypto -ldl

SOURCES = ctru.c poly.c ntt.c reduce.c coding.c matrix.c randombytes.c aes256ctr.c cbd.c\
  cpucycles.c speed.c sha512.c pack.c kem.c fips202.c 
HEADERS = params.h ctru.h poly.h reduce.h ntt.h coding.h matrix.h \
  crypto_stream.h randombytes.h cpucycles.h speed.h sha2.h pack.h kem.h cbd.h fips202.h crypto_hash_sha3256.h

all:  test_kem768 test_speed768 

test_kem768: test_kem.c $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -DCTRU_ALPHA=3 $< $(SOURCES) -o $@ $(LDFLAGS)

test_speed768: test_speed.c $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -DCTRU_ALPHA=3 $< $(SOURCES) -o $@ $(LDFLAGS)


.PHONY: clean

clean:
	rm -f *~ *~
	rm -f test_kem768
	rm -f test_speed768	

