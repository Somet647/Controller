# Custom ATmega32U4 USB HID Gamepad

A custom USB gamepad designed and built around an ATmega32U4 microcontroller. This project started as a breadboard prototype using an Arduino and was developed into a standalone custom PCB, combining embedded firmware, digital and analog inputs, USB HID communication, and PCB design.

---

## Features

### Hardware & PCB Design
* **Custom ATmega32U4 Design:** Designed a standalone gamepad around the ATmega32U4, integrating the microcontroller, clock circuitry, USB interface, programming header, analog inputs, and digital inputs onto a custom PCB.
* **USB-C Interface:** Implemented a USB-C device interface with 5.1kΩ CC pull-down resistors, 22Ω D+/D− series resistors, and dedicated power decoupling for reliable communication.
* **Analog Input System:** Integrated analog data processing using the ATmega32U4's ADC channels to provide joystick functionality.
* **Power & Decoupling:** Distributed the +5V USB supply across the board with local 100nF and bulk 10μF capacitors to reduce noise and add stability.
* **External Clock:** Implemented a 16MHz crystal oscillator with 22pF load capacitors to provide the ATmega32U4 with a stable system clock.
* **ISP Programming:** Added a dedicated 6-pin AVR ISP header for directly programming the ATmega32U4 on the custom PCB.
* **PCB Layout:** Designed the complete schematic and multi-layer PCB layout in KiCad.

### Firmware
* **Standalone USB HID:** Configured the ATmega32U4 as a USB HID gamepad, providing direct PC compatibility without a secondary USB-to-UART bridge or custom PC software.
* **Analog Input Handling:** Used the ATmega32U4's 10-bit ADC to support 2 analog joysticks across 4 axes (X, Y, Rx, Ry).
* **Digital Input Handling:** Configured 14 button inputs using the MCU's internal pull-up resistors and active-low logic, eliminating the need for external pull-up components.
* **Low-Latency Input**: Sampled button and analog inputs at approximately 100 Hz using a 10 ms control loop for responsive controller input.
* **Input Mapping:** Developed a software mapping between the ATmega32U4 GPIO/ADC pins and the corresponding gamepad buttons and analog axes.

---

## Hardware Specifications

| Component            | Specification                      |
| -------------------- | ---------------------------------- |
| **MCU**              | ATmega32U4                         |
| **Supply**           | 5 V from USB                       |
| **USB Connector**    | USB-C                              |
| **USB Data**         | D+ / D− with 22 Ω series resistors |
| **CC Configuration** | 5.1 kΩ pull-downs on CC1/CC2       |
| **Digital Inputs**   | 14 buttons, internal pull-ups      |
| **Analog Inputs**    | 4 × 10-bit ADC channels            |
| **Analog Controls**  | 2 × dual-axis joysticks            |
| **System Clock**     | 16 MHz external crystal            |
| **ISP**              | 6-pin AVR ISP header               |
| **PCB**              | Custom multi-layer PCB             |
| **Design Software**  | KiCad                              |


---

## Repository Structure

```text
├── firmware/         # C++ / Arduino controller logic and USB HID descriptors
├── hardware/         # KiCad schematics, PCB board layout, and Gerber manufacturing files
└── README.md         # Project technical summary
