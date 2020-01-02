# Controlling a BLDC with an Atmega328p

This project implements a controller for a Brushless Direct Current Moter (BLDC), by measuring the Back EMF. For more details on the theory read the project report.

## AVR Developement with Docker
The project uses docker to compile and flash the the C code onto the microcontroller. The container starts by running visual studio code. The docker-compose.yml file configures the container to make developement and flashing possible.