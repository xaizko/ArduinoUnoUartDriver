# UnoUart0 — Lightweight UART0 driver for Arduino Uno

A minimal, no-dependency UART driver for the ATmega328P / Arduino Uno that provides simple blocking transmit/receive helpers using the onboard USART0 registers.

## Features

- Tiny, single-class driver with a small API: `transmit`, `print`, `receive`, `receiveString`.
- Blocking (polling) I/O — simple and deterministic for small projects.
- Configurable compile-time `CLOCK_FREQUENCY` and `BAUDRATE` macros in `src/UnoUart0.hpp`.
- Direct register access (low-level) for AVR performance and minimal overhead.

## Files

- [src/UnoUart0.hpp](src/UnoUart0.hpp) — Driver header and register definitions
- [src/UnoUart0.cpp](src/UnoUart0.cpp) — Driver implementation
- [src/ArduinoTestCode.cpp](src/ArduinoTestCode.cpp) — Small example that uses the driver

## API (quick reference)

- `UnoUart0()` — Constructor: configures UBRR, enables RX/TX, and sets 8-bit mode.
- `void transmit(char c)` — Send a single character (blocks until ready).
- `void print(const char* str)` — Send a null-terminated C string.
- `char receive()` — Receive a single character (blocks until data available).
- `void receiveString(char* buffer, uint16_t maxLength)` — Receive characters into `buffer` until newline/CR or `maxLength-1` characters; buffer is NUL-terminated.

## Usage

Drop `UnoUart0.hpp` and `UnoUart0.cpp` into your Arduino/AVR project and include the header where needed. Example adapted from `src/ArduinoTestCode.cpp`:

```cpp
#include "UnoUart0.hpp"

#define MAX_LENGTH 64

UnoUart0 uart; 
char textBuffer[MAX_LENGTH];

void setup() {
    uart.print("Enter a string:\n");
}

void loop() {
    uart.receiveString(textBuffer, MAX_LENGTH);
    uart.print(textBuffer);
    uart.print("\n");
    delay(10);
}
```

## Notes & Caveats

- This driver is blocking: `transmit` and `receive` will stall the CPU while waiting. It is intentionally simple and not suitable for high-throughput or low-latency multitasking without adaptation.
- The driver uses hard-coded AVR register addresses for USART0 and is intended for ATmega328P-based boards (e.g., Arduino Uno).
- Change `CLOCK_FREQUENCY` and `BAUDRATE` in `src/UnoUart0.hpp` to match your board and desired serial speed.

## Testing

- Build and run on an AVR toolchain (PlatformIO, Arduino CLI, or avr-gcc/avrdude). Example with PlatformIO: create a `platformio.ini` for `atmelavr`/`uno`, add these files to `src/`, then run `pio run` and `pio run --target upload`.

## Improvements

Contributions and improvements are welcome — examples: add non-blocking APIs, optional interrupt-driven mode, or a C++ stream-style wrapper.
