## EEPROM Examples — read_write_eeprom

This folder contains example code for reading from and writing to the Arduino's internal EEPROM, plus a few small code snippets demonstrating related techniques.

Contents

- `read_write_eeprom.ino` — Interactive serial command interface to read and write bytes in internal EEPROM. The sketch listens on Serial (9600 baud) and accepts simple text commands:
  - `read <address>` — reads a single byte from EEPROM at numeric `<address>` and prints the value.
  - `write <address> <value>` — writes a byte (`0`–`255`) to EEPROM at the given `<address>`.
  The sketch prints helpful prompts and command results over Serial.

- `code_snippets/1.read_and_write_commands.ino` — Short example(s) showing the basic read/write patterns used with `EEPROM.read()` and `EEPROM.write()`.
- `code_snippets/2.using_mask_and_little_endian.ino` — Small examples demonstrating masking and little-endian techniques when storing multi-byte values in EEPROM.

Quick start

1. Open `read_write_eeprom.ino` in the Arduino IDE.
2. Connect your Arduino and select the correct board and serial port.
3. Upload the sketch.
4. Open the Serial Monitor and set the baud rate to `9600` and the line ending to `Newline` (or `Both NL & CR`) so pressing Enter sends a terminator.
5. Try commands such as:

```
read 10
write 10 123
read 10
```

Notes & limits

- Addresses: use addresses in the valid range (0 .. `EEPROM.length() - 1`). Attempting to access out-of-range addresses will result in an error message.
- Values: the examples store single bytes (0–255). If you need to store larger types (ints, longs, floats, structs), see `code_snippets/2.using_mask_and_little_endian.ino` or serialize the data into bytes.
- EEPROM wear: EEPROM has a limited write endurance (usually ~100k writes per cell). Avoid frequent writes to the same address in rapid loops; consider wear-leveling or buffering strategies for frequent updates.

Troubleshooting

- No Serial output: confirm correct COM port and that Serial Monitor is set to 9600 baud.
- "Address out of range" errors: pick a smaller address or check `EEPROM.length()` for your board.
- Unexpected values: remember EEPROM retains data between resets and power cycles — use `write` to set known values for testing.

Suggested improvements

- Add safety checks or a confirmation step before writes for production use.
- Provide multi-byte read/write helpers (store 16/32-bit values across multiple addresses) and add commands to read/write blocks.
- Add a `dump` or `hexdump` command to display a range of EEPROM addresses for debugging.

Location

Path: `arduino/4.eeprom`

If you want, I can:
- Add a `dump` command to `read_write_eeprom.ino` that prints a small block of EEPROM bytes.
- Add a helper that writes/reads 16-bit and 32-bit values using little-endian ordering and update the README with examples.
