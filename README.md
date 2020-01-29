# IFX007T-Motor-Control
IFX007T NovalithIC™ based DC motor control 

## IFX007T-Motor-Control


<!-- [![Build Status](https://www.infineon.com/cms/en/product/evaluation-boards/bldc-shield_ifx007t/)] -->

C++ library of Infineon **IFX007T NovalithIC™ based DC motor control** family for various kind of motor control applications

 1. [Overview](#ovw)
 2. [Supported Hardware](#s-hw)
 3. [Software Requirements](#sw-req)
 4. [Library Usage](#lib-usage)
 5. [Demo Application Example](#demo-ex)
 6. [References](#refs)

<a name="ovw"></a>

## 1. Overview

###  Hardware Compatible with Arduino 

The (BL)DC motor control shield from Infineon technologies is a high current motor control board compatible with Arduino and Infineon’s XMC4700 Boot Kit. It is equipped with three smart IFX007T half-bridges. The BLDC motor control shield is capable to drive one BLDC motor. Alternatively, it can be used to drive one or two bi-directional DC motors (H-Bridge configuration, cascaded to support second motor) or up to three uni-directional BLDC motors (half-bridge configuration).The implemented integrated IFX007T NovalithIC™ half-bridges can be controlled by a PWM via the IN Pin. Interfacing to a microcontroller is made easy by the integrated driver IC which features logic level inputs, diagnosis with current sense, slew rate adjustment, and dead time generation. The three IFX007T half-bridges are also fully protected against over-temperature, under-voltage, overcurrent and short circuit events.

<br>

<img src="images\BLDC.png" height="340px" width="500px">

<a name="s-hw"></a>

## 2. Supported Hardware

### Arduino and XMC platforms 
The library has been customized for the XMC boards and the Arduino environment. 


<a name="sw-req"></a>

## 3. Software Requirements

### Supported Toolchain Software 

The library examples has been built successfully with the following toolchain software:

Framework | IDE         | Versions                    | MCU Platform Core Libs        | Versions  
---       | ---         |---                          | ---                           |--- 
Arduino   | Arduino IDE | 1.8.9                       | [XMC for Arduino](https://github.com/Infineon/XMC-for-Arduino)     | 1.2.1     
Arduino   | PlatformIO  | Home 2.0.2·Core + 4.0.0a8   | [Infineon XMC](https://github.com/Infineon/platformio-infineonxmc) | 1.1.2 

### Software Dependencies

There are no additional library dependencies required by the IFX007T-Motor-Control library or its examples.

<a name="lib-usage"></a>

## 4. Library Usage

### Source Code Documentation

Find the source code documentation in **Doxygen** format on the following [link](to be replaced)

### Arduino IDE

If you are new to Arduino IDE, please [download](https://www.arduino.cc/en/Main/Software) and install it first.

The official Arduino Boards are already available in the IDE, but other third party boards as the Infineon XMC MCU based need to be explicitly included. Follow the instructions in the [link](https://github.com/Infineon/XMC-for-Arduino#installation-instructions) to add the XMC board family to Arduino. Once installed, you can select the one of the supported board from the menu *Tools > Board:...* and configure its parameters.

Then we simply need to install the library to use it in your project:

1. **Install the library**. Download this library as a .zip file (get the latest release version [here](to be replacedttps://github.com/Infineon/ifx.../releases)). Install the library in the Arduino IDE in the menu *Sketch > Include Library > Add .ZIP library*.

2. **Include it in your sketch**. With the library installed in the Arduino IDE, you can include it from the menu "Sketch > Include Library > IFX007T-Motor-Control". The header ``` #include <IFX007T-Motor-Control.h> ``` will be added to your sketch. You can also open and test one of the examples provided in  *File > Examples > IFX007T-Motor-Control* (find an example in the [](#demo-ex) section).

### PlatformIO 

If you are new to PlatformIO, download and install first Visual Studio Code and the PlatformIO plugin. Please follow the instructions on the [official website](https://docs.platformio.org/en/latest/ide/pioide.html). Then go through [this tutorial](https://diyprojects.io/install-ide-platformio-extension-visual-studio-code-vscode-windows-32-bit-linux/#.XOVQP44zYnI) to get started with PlatformIO in VSCode and create a new project. 

With the project created, now the library and its dependencies can be configured in the ***Platform.ini* Project File**. This file, located in the project root folder, includes one (or several) building environments *[env:__]*. In the *environment* section, the platform, board, and framework are specified. PlatformIO will take care of downloading and installing all dependencies.

```
[env:xmc1100/arduino]
platform = infineonxmc
board = xmc1100/arduino
framework = arduino

lib_deps =
# Using a library name
IFX007T-Motor-Control
    
# Using the repository URL
https://github.com/Infineon/IFX007T-Motor-Control
```

 

### Other hardware platforms and frameworks

The hardware interfaces for the Arduino hardware platforms have been implemented using the [Arduino reference](https://www.arduino.cc/reference/en/) libraries. 

Additional hardware interface implementations can be added here for other platforms, MCU core libraries, toolchains and frameworks based on C/C++. 
Currently, no toolchain or framework integration other than Arduino is provided.

<a name="demo-ex"></a>

## 5. Demo Application Example

How to make a smoothie with our new Motor Driver (IFX007) for Industrial Applications
Witness the unboxing, presentation and initial operation of the IFX007T – Infineon’s new motor driver. Watch how easy it is to connect the IFX007T shield to an Arduino and to use it to make a delicious mango lassi with a 24V smoothie maker. The smart integrated half-bridge IFX007T is the perfect motor driver for all kinds of industrial and home applications. It can be used to control the 12V-24V motors of drones, power tools, kitchen appliances, vacuums, and even industrial robots. It also provides a variety of protection and diagnosis features like current sense to guarantee the highest quality of your applications. To watch demo application example please visit: [Mango Smoothie Maker](https://www.youtube.com/watch?v=5yQY-CGptBI)

<img src="images\smoothie.png" height="340px" width="700px">
<a name="refs"></a>  

## 6. References

### Online Simulator
-[Online Simulator for Bi Directional Motor](https://www.infineon.com/dgdl/Infineon-motor_brushed_24V_full-bridge_IFX007T_with_torque-ST-v01_00-EN.htm?fileId=5546d46265f064ff01665a3d632e5609)

-[Online Simulator for uni Directional Motor](https://www.infineon.com/dgdl/Infineon-motor_brushed_24V_half-bridge_IFX007T_with_torque-ST-v01_00-EN.htm?fileId=5546d46265f064ff01665a3d5d3b5604)
### Useful Links
 - [Infineon for Makers](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/)
 - [Arduino](https://www.arduino.cc/)
 - [PlatformIO](https://platformio.org/)
