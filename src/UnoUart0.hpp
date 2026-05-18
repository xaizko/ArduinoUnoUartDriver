#include <cstdint> 

#define CLOCK_FREQUENCY 16000000 // 16MHz
#define BAUDRATE 9600

class UnoUart0 {
	public:
		UnoUart0();
		void transmit(char c);
		void print(const char* str);
		char receive();

	private:
		// NOTE:
		// There might be an issue with the naming convention depending on where you upload the code
		// Rename the registers to get rid of the error

		// Specs found here: 
		// https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf
		inline static volatile uint8_t* const UCSR0A = reinterpret_cast<uint8_t*>(0xC0);
		inline static volatile uint8_t* const UCSR0B = reinterpret_cast<uint8_t*>(0xC1);
		inline static volatile uint8_t* const UCSR0C = reinterpret_cast<uint8_t*>(0xC2);
		inline static volatile uint8_t* const UBBR0L = reinterpret_cast<uint8_t*>(0xC4);
		inline static volatile uint8_t* const UBBR0H = reinterpret_cast<uint8_t*>(0xC5);
		inline static volatile uint8_t* const UDR0 = reinterpret_cast<uint8_t*>(0xC6);
};
