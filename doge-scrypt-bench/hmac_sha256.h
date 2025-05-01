#ifndef SIMPLE_HMAC_SHA256_H
#define SIMPLE_HMAC_SHA256_H

#include <cstdint>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <cstring>

class CHMAC_SHA256
{
public:
    static const size_t OUTPUT_SIZE = 32;

    CHMAC_SHA256(const uint8_t *key, size_t keylen)
    {
        ctx = HMAC_CTX_new();
        HMAC_Init_ex(ctx, key, keylen, EVP_sha256(), nullptr);
    }

    ~CHMAC_SHA256()
    {
        HMAC_CTX_free(ctx);
    }

    void Write(const uint8_t *data, size_t len)
    {
        HMAC_Update(ctx, data, len);
    }

    void Finalize(uint8_t hash[OUTPUT_SIZE])
    {
        unsigned int len = OUTPUT_SIZE;
        HMAC_Final(ctx, hash, &len);
    }

    void Copy(CHMAC_SHA256 *dest) const
    {
        dest->ctx = HMAC_CTX_new();
        HMAC_CTX_copy(dest->ctx, ctx);
    }

private:
    HMAC_CTX *ctx;
};

#endif // SIMPLE_HMAC_SHA256_H
