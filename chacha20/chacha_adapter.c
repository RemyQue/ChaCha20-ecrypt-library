// Remy Q's ChaCha adapter

#include "chacha.h"
#include "ecrypt-sync.h"

// This file serves as an adapter between the ECRYPT ChaCha implementation
// and our simplified chacha.h interface

void chacha_keysetup(chacha_ctx* ctx, const uint8_t* k, uint32_t kbits) {
    // forward to the ECRYPT implementation
    ECRYPT_keysetup((ECRYPT_ctx*)ctx, k, kbits, 64);  // Use 64-bit IV size
}

void chacha_ivsetup(chacha_ctx* ctx, const uint8_t* iv) {
    // forward to the ECRYPT implementation
    ECRYPT_ivsetup((ECRYPT_ctx*)ctx, iv);
}

void chacha_encrypt(chacha_ctx* ctx, const uint8_t* m, uint8_t* c, uint32_t bytes) {
    // Forward to the ECRYPT implementation
    ECRYPT_encrypt_bytes((ECRYPT_ctx*)ctx, m, c, bytes);
}