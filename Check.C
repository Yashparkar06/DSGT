#include <stdio.h>
#include <string.h>

// Function to calculate the checksum
unsigned short calculateChecksum(char *message) {
    unsigned short checksum = 0;
    int i;

    for (i = 0; i < strlen(message); i++) {
        checksum += (unsigned short)message[i];
    }

    return checksum;
}

int main() {
    char message[100];
    unsigned short originalChecksum, calculatedChecksum;

    printf("Enter a message: ");
    gets(message);

    // Calculate the original checksum
    originalChecksum = calculateChecksum(message);
    
    printf("Original Checksum: %u\n", originalChecksum);

    printf("Enter the received message: ");
    gets(message);

    // Calculate the checksum for the received message
    calculatedChecksum = calculateChecksum(message);

    printf("Calculated Checksum: %u\n", calculatedChecksum);

    // Verify the checksum
    if (originalChecksum == calculatedChecksum) {
        printf("Checksum is correct. No errors detected.\n");
    } else {
        printf("Checksum error detected. Message may be corrupted.\n");
    }

    return 0;
}
