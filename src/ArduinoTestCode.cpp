#include "UnoUart0.hpp"

int main() {

	// Initialize Driver
	UnoUart0 logger; 

	while(true) {
		logger.print("Hello from direct-address bare metal!\n");
	}
	return 0;
}
