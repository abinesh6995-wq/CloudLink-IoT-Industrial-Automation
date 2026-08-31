# CloudLink: IoT-Based Industrial Automation and Smart Control System

## Project Overview

CloudLink is an IoT-based industrial automation and smart control system using the LPC2129 ARM7 microcontroller, ESP8266 Wi-Fi module, Arduino IoT Cloud, HW-316 4-channel relay module and L293D motor driver.

The LPC2129 acts as the main controller. The ESP8266 provides Wi-Fi connectivity and communicates with Arduino IoT Cloud.

The system allows electrical loads and a DC motor to be controlled remotely using a cloud dashboard.

## Main Components

- LPC2129 ARM7 Microcontroller
- ESP8266 ESP-01 Wi-Fi Module
- Arduino IoT Cloud
- HW-316 4-Channel Relay Module
- L293D Motor Driver
- DC Motor
- 5V Power Supply
- 3.3V Power Supply

## Pin Configuration

| LPC2129 Pin | Connected Device | Function |
|---|---|---|
| P0.1 / RXD0 | ESP8266 TX | UART Receive |
| P0.16 | HW-316 IN1 | Relay 1 |
| P0.17 | L293D | DC Motor |
| P0.18 | HW-316 IN2 | Relay 2 |
| P0.19 | HW-316 IN3 | Relay 3 |
| P0.20 | HW-316 IN4 | Relay 4 |

## UART Configuration

- Baud Rate: 9600
- Data Bits: 8
- Stop Bits: 1
- Parity: None

## Relay Operation

The HW-316 relay module uses active-low control in this project.

- P0.16 LOW → Relay 1 ON
- P0.16 HIGH → Relay 1 OFF

Other relay channels:

- P0.18 → Relay 2
- P0.19 → Relay 3
- P0.20 → Relay 4

## Motor Operation

The DC motor is controlled through the L293D motor driver.

- P0.17 HIGH → Motor ON
- P0.17 LOW → Motor OFF

The motor is not connected directly to the LPC2129 GPIO.

## Cloud Communication

Arduino IoT Cloud
↓
ESP8266
↓
UART
↓
LPC2129
↓
Relay / Motor

## Commands

### Relay 1

RELAY1ON

RELAY1OFF

### Relay 2

RELAY2ON

RELAY2OFF

### Relay 3

RELAY3ON

RELAY3OFF

### Relay 4

RELAY4ON

RELAY4OFF

### Motor

MOTORON

MOTOROFF

## Software

- Keil µVision5
- Embedded C
- Arduino IDE
- Arduino IoT Cloud
- Flash Magic
- Serial Terminal

## Applications

- Industrial automation
- Remote equipment control
- Machine control
- Cooling and ventilation
- Conveyor systems
- Water pumping
- Smart electrical load control

## Future Enhancements

- Temperature monitoring
- Current and voltage monitoring
- Motor speed control
- Fault detection
- Overload protection
- Cloud data logging
- Automatic scheduling
- Industrial sensor integration

## Author

Your Name

## License

This project is developed for educational and demonstration purposes.
