#include <cstdint>
#include <cstdio>

enum MS_MISC { MS_KEY_SIZE = 6 };

typedef uint8_t byte;

typedef struct {
  byte keyByte[MS_KEY_SIZE];
} MIFARE_Key;

void print_bytes(byte b[6]);
bool compareKeys(MIFARE_Key key1, MIFARE_Key key2);
MIFARE_Key brute_force_key(MIFARE_Key key);

int main() {
    MIFARE_Key key = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};

    // Brute force search for key
    MIFARE_Key foundKey = brute_force_key(key);

    print_bytes(foundKey.keyByte);

    return 0;
}

void print_bytes(byte b[6]) {
    printf("-=-=-=-=-=-=-=-=-=-=\n");
    printf("1  2  3  4  5  6\n");
    for (byte i = 0; i < 6; i++) {
        printf("%.1x ", b[i]);
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=\n");
}

bool compareKeys(MIFARE_Key key1, MIFARE_Key key2) {
    for (int i = 0; i < MS_KEY_SIZE; ++i) {
        if (key1.keyByte[i] != key2.keyByte[i]) {
            return false;
        }
    }
    return true;
}

MIFARE_Key brute_force_key(MIFARE_Key key) {
    MIFARE_Key currentKey;
    unsigned long long total_combinations = 1ULL << (8 * MS_KEY_SIZE);
    printf("total_combinations: %llu\n", total_combinations);
    int current_combination = 0;

    for (byte b1 = 0; b1 <= 0xFF; ++b1) {
        for (byte b2 = 0; b2 <= 0xFF; ++b2) {
            for (byte b3 = 0; b3 <= 0xFF; ++b3) {
                for (byte b4 = 0; b4 <= 0xFF; ++b4) {
                    for (byte b5 = 0; b5 <= 0xFF; ++b5) {
                        for (byte b6 = 0; b6 <= 0xFF; ++b6) {
                            currentKey.keyByte[0] = b1;
                            currentKey.keyByte[1] = b2;
                            currentKey.keyByte[2] = b3;
                            currentKey.keyByte[3] = b4;
                            currentKey.keyByte[4] = b5;
                            currentKey.keyByte[5] = b6;

                            current_combination++;
                            int progress = (current_combination * 100) / total_combinations;

                            // Print progress every 1% increment
                            if (progress % 10 == 0) {
                                printf("Progress: %d%%\n", progress);
                            }
                            
                            if (compareKeys(currentKey, key)) {
                                return currentKey;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    // Return an empty key if not found
    return {};
}
