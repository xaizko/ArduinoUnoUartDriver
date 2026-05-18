#include "UnoUart0.hpp"

int main() {

	// Initialize Driver
	UnoUart0 logger; 

	while(true) {
		char input = logger.receive();
		logger.print("Received: ");
		logger.transmit(input);
		logger.print("\n");
	}
	return 0;
}
