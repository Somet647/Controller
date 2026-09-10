# Custom ATmega32U4 USB HID Gamepad

A custom USB gamepad designed and built around an ATmega32U4 microcontroller. This project started as a breadboard prototype using an Arduino and was developed into a standalone custom PCB, combining embedded firmware, digital and analog inputs, USB HID communication, and PCB design.

---

## Features
* ATmega32U4 microcontroller with native USB support
* USB-C device interface
* USB HID gamepad communication
* 13 digital buttons
* 4 analog inputs using the ATmega32U4 ADC
* 16 MHz external crystal
* 6-pin AVR ISP/ICSP programming header
* Custom power distribution and decoupling
* Fully standalone design without an Arduino development board

### Embedded Firmware
* **USB HID Capability:** Configured the ATmega32U4’s internal USB controller to act as a plug-and-play game controller without secondary USB-to-UART bridge chips or third-party software.
* **Low-Latency Performance**: Optimized joystick response times and button debouncing to ensure instant, lag-free inputs.

### Hardware & PCB Design
* **AVCC Filtering:** Implemented a $10\mu\text{H}$ inductor and $100\text{nF}$ capacitor LC filter network to isolate the ADC power supply, reducing analog signal noise on joystick inputs.
* **Power & Signal Integrity:** Placed $100\text{nF}$ high-frequency ceramic decoupling capacitors adjacent to all VCC/UVCC pins. Added an RC filter ($10\text{k}\Omega$ / $100\text{nF}$) on the RESET line to suppress transient voltage spikes.
* **Layout:** Custom schematic capture and multi-layer trace routing designed in KiCad.
* Hardware & PCB Design
* Custom ATmega32U4 Design: Designed a standalone gamepad around the ATmega32U4, integrating the microcontroller, clock circuitry, USB interface, programming header, analog inputs, and digital inputs onto a custom PCB.
* USB-C Interface: Implemented a USB-C device interface with 5.1kΩ CC pull-down resistors, 22Ω D+/D− series resistors, and dedicated power decoupling for reliable USB communication.
* Analog Input System: Integrated four potentiometers with the ATmega32U4's ADC channels to provide four independent analog controls for the gamepad.
* Power & Decoupling: Distributed the +5V USB supply across the board with local 100nF and bulk 10μF capacitors to reduce supply noise and provide stable operation for the microcontroller and peripherals.
* External Clock: Implemented a 16MHz crystal oscillator with 22pF load capacitors to provide the ATmega32U4 with a stable system clock.
* ISP Programming: Added a dedicated 6-pin AVR ISP header for directly programming the ATmega32U4 on the custom PCB.
* PCB Layout: Designed the complete schematic and multi-layer PCB layout in KiCad, including component placement, power distribution, signal routing, and manufacturing considerations.

---

## Hardware Specifications

| Component | Specification |
| :--- | :--- |
| **Microcontroller** | ATmega32U4 (8-bit AVR @ 16MHz, 5V) |
| **Clock Source** | 16MHz External Crystal Oscillator + 22pF load caps |
| **Connectivity** | USB-C (USB 2.0 Full-Speed HID) |
| **Inputs** | 14 Digital Buttons, 4 Analog Axes (2 Dual-Axis Joysticks) |

---

## Repository Structure

```text
├── firmware/         # C++ / Arduino controller logic and USB HID descriptors
├── hardware/         # KiCad schematics, PCB board layout, and Gerber manufacturing files
├── docs/             # Technical reference notes and schematic diagrams
└── README.md         # Project technical summary
