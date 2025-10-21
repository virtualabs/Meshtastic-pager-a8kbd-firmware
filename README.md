# A8 Mini 2.4 GHz keyboard firmware for Virtu's DIY Meshtastic Pager

This opensource firmware for the A8 mini 2.4 GHz keyboard from AliExpress
is provided as-is with absolutely no warranty, use it at your own risk.

## Requirements

This project must be compile with [Moun River Studio 2 IDE](https://www.mounriver.com/download). A precompiled HEX file is provided in this repository for those who don't want
to install this IDE.

[Wchisp](https://github.com/ch32-rs/wchisp) is used to flash this firmware file on the target chip, following the flashing
procedure detailed below.

## Build from source

- Open the `CH582M.wvproj` file with Moun River Studio 2
- In the _Project_ menu entry, click _Build_
- Output _HEX_ file is located in the _obj_ folder

## Preparing the keyboard PCB

![Keyboard PCB pinout](img/pcb-pinout.png)

The keyboard PCB has an expansion port composed of a 5-pin connector located at top right hand corner
of the circuit board with pins labeled _PB22_, _3V3_, _UD-_, _UD+_, _GND_.


## Flashing firmware

The following steps are required to flash this firmware into the CH582M SoC:

1. Disconnect the PCB USB connector from any host
2. Make sure the keyboard PCB ON/OFF switch is set to ON
3. Connect the D+ pin to 3V3 with a jumper wire
4. In a dedicated shell, prepare the following command (but DO NOT PRESS ENTER): `wchisp flash CH582M.hex`
5. Plug the USB cable in the keyboard's USB port and then to the computer
6. Disconnect the D+ pin from 3V3 and as fast as possible hit the ENTER key to run the command prepared at step 4
7. The target CH582M should be detected and programmed

