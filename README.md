# Digital Visitor Counter Using 8051

## About the Project

The Digital Visitor Counter is an 8051 microcontroller-based project designed to count the number of people entering and leaving a designated area.

The system uses two sensors to detect the direction of movement. When a person enters, the visitor count is increased, and when a person exits, the count is decreased.

The current visitor count is displayed on a 16×2 LCD.

## Features

- Automatic entry detection
- Automatic exit detection
- Visitor count increment and decrement
- Real-time count display on 16×2 LCD
- Count does not go below zero
- Direction detection using two sensors

## Components Used

- 8051 Microcontroller
- 2 × Sensors
- 16×2 LCD Display
- Crystal Oscillator
- Resistors
- Capacitors
- Power Supply

## Software Used

- **Keil µVision** – Embedded C programming and compilation
- **Proteus** – Circuit design and simulation

## Working Principle

Two sensors are used to determine whether a person is entering or leaving.

### Entry

When Sensor 1 is triggered first, followed by Sensor 2:

`Sensor 1 → Sensor 2`

The system identifies this as an entry and increases the visitor count by 1.

### Exit

When Sensor 2 is triggered first, followed by Sensor 1:

`Sensor 2 → Sensor 1`

The system identifies this as an exit and decreases the visitor count by 1.

The updated count is displayed on the 16×2 LCD.

## Programming

The project is programmed in **Embedded C** for the 8051 microcontroller.

The program handles:

- Sensor input detection
- Entry and exit detection
- Visitor count calculation
- LCD initialization
- LCD data and command control
- Real-time visitor count display

## Circuit Schematic

The circuit was designed and simulated using Proteus.

![Circuit Schematic](schematic.png)

## 🎥 Demo

A screen recording demonstrating the working of the visitor counter is included below.

[▶️ View Demo Video](Demo/visitor_counter_demo.mp4)

## Learning Outcomes

This project provided hands-on experience with:

- 8051 microcontroller programming
- Embedded C
- Sensor interfacing
- LCD interfacing
- Digital counting logic
- Circuit simulation using Proteus
- Keil µVision development environment

## Project

A beginner-level embedded systems project developed using the **8051 microcontroller**.
