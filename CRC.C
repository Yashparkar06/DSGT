#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CRC32_POLYNOMIAL 0xEDB88320
#define INITIAL_CRC32_VALUE 0xFFFFFFFF

uint32_t calculate_crc32(const uint8_t *data, size_t length) {
    uint32_t crc = INITIAL_CRC32_VALUE;
    for (size_t i = 0; i < length; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ CRC32_POLYNOMIAL;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc ^ INITIAL_CRC32_VALUE;
}

int main() {
    // Define your data as a hexadecimal string
    const char* message = "0123456789";
    // The expected CRC-32 checksum for your data (in hexadecimal)
    const uint32_t expected_crc32 = 0xCBF43926;

    size_t message_length = strlen(message);
    uint32_t crc32_result = calculate_crc32((const uint8_t*)message, message_length);

    printf("Message: %s\n", message);
    printf("CRC-32 Result: 0x%08X\n", crc32_result);

    if (crc32_result == expected_crc32) {
        printf("CRC-32 checksum matches the expected value.\n");
    } else {
        printf("CRC-32 checksum does not match the expected value.\n");
    }

    return 0;
}
