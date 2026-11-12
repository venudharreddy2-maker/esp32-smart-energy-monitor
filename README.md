# ESP32 Smart Energy Monitoring System

## Overview
An ESP32-based smart energy monitoring project that simulates voltage and current sensing, calculates electrical power and energy consumption, and displays readings on a 16x2 I2C LCD.

## Features
- Analog voltage and current input using potentiometers
- ESP32 ADC readings through GPIO 34 and GPIO 35
- Real-time voltage and current calculations
- Power calculation using P = V × I
- Energy consumption calculation in Wh
- 16x2 I2C LCD display
- Serial Monitor output

## Hardware Components (Wokwi Simulation)
- ESP32 development board
- 2 potentiometers (simulated sensors)
- 16x2 I2C LCD

## Pin Connections

 Component - ESP32 Pin 

 Voltage potentiometer signal - GPIO 34 
 Current potentiometer signal - GPIO 35
 LCD SDA - GPIO 21 
 LCD SCL - GPIO 22 
 LCD VCC - 3V3 
 LCD GND - GND 

## Calculations
- Voltage = ADC reading mapped to 0–250 V
- Current = ADC reading mapped to 0–10 A
- Power (W) = Voltage × Current
- Energy (Wh) = Power × Elapsed time (hours)

## Simulation
Built and tested using Wokwi.

[Open Wokwi Simulation](https://wokwi.com/projects/480460138952777729)

## Technologies Used
- Embedded C++ / Arduino framework
- ESP32
- ADC
- I2C communication
- Wokwi Simulator

## Important Note
This project uses simulated sensor inputs for learning and demonstration. It is not a calibrated or certified electricity meter and is not designed for direct mains-voltage measurement.
## Project Screenshots



### Circuit Diagram
![ESP32 Circuit](<esp circuit screenshot.png>)

### Simulation Output
![ESP32 LCD Display](<esp simulation.png>)

## Author
Venudharrreddy2-maker
