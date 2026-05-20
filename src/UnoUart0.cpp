#include "UnoUart0.hpp"

UnoUart0::UnoUart0() {

	// Grab the UBBR registers
	// Ref: Page 621
	uint16_t ubbr_val = (CLOCK_FREQUENCY / (16 * BAUDRATE)) - 1;
	*UBBR0H = static_cast<uint8_t>(ubbr_val >> 8);
	*UBBR0L = static_cast<uint8_t>(ubbr_val);

	// Active RX and TX
	// Ref: Page 202
	*UCSR0B |= (1 << 4) | (1 << 3);
	
	// Set Mode to 8 Bit
	// Ref: Page 203
	*UCSR0C = (1 << 2) | (1 << 1);
}

void UnoUart0::transmit(char c) {
	// Check if if UDRN is ready to receive new data
	while(!(*UCSR0A & (1 << 5))) {
		// Stalls until ready
	}

	*UDR0 = c;
}

void UnoUart0::print(const char* str) {
	while(*str) {
		transmit(*str++);
	}
}

char UnoUart0::receive(){
	// Check if receive completed 
	while(!(*UCSR0A & (1 << 7))) {
		// Stalls until ready
	}

	return *UDR0;
}

void UnoUart0::receiveString(char* buffer, uint16_t maxLength) {
	uint16_t index = 0;

	while (index < (maxLength - 1)) {
		char c = receive();
		if (c == '\r' || c == '\n') {
			break;
		}

		buffer[index] = c;
		index++;
	}
	
	buffer[index] = '\0';
}
