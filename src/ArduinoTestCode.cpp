#include "UnoUart0.hpp"

#define MAX_LENGTH 64

int main() {

	// Initialize Driver
	UnoUart0 logger; 

	char textBuffer[MAX_LENGTH];

	logger.print("Enter a string:\n");

	while(true) {
		logger.receiveString(textBuffer, MAX_LENGTH);
		logger.print(textBuffer);
		logger.print("\n");
	}
	return 0;
}
