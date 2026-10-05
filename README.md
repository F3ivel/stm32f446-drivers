<h1 align="center">Welcome to stm32f446-drivers 👋</h1>

This project contains low-level drivers for the STM32F446xx family. For a list of drivers I plan to implement, see [Drivers I want to implement](#drivers-i-want-to-implement). You can find a list of already implemented drivers [here](#drivers-already-implemented). If you are asking yourself what these drivers can do and how to use them, the project comes with a "Doxyfile" which you can use to create the documentation for the drivers. In the section [Documentation](#documentation) you will find instructions on how to build the documentation. 

## Drivers I want to implement 🎯

- GPIO
- Basic Timers
- ADC
- UART

## Drivers already implemented ✅
- Basic Timers

## Documentation

### Prerequisites:

In order to build the documentation for this project you will need the program [doxygen](https://www.doxygen.nl/).

However if you do not want additional software on your computer to be installed, you can also look at the header file for the specific driver, to understand how to use it correctly.

### How to build the documentation:

To build the documentation for the drivers, you just need to be in the root directory of this project and type the following in a console:

`doxygen` and then press enter

Doxygen now creates the documentation and after that you will find in the root directory a new folder named "html". Within this folder, double click the "index.html" file and the documentation will be shown in your browser.
