# C-Code Commands

The RoboRot firmware accepts G-Code & M-Code commands passed by the serial terminal.

## Introduction to G-Code

G Code is a special programming language that is interpreted by Computer Numerical Control (CNC)
machines to create motion and other tasks.

The biggest difference between G & M Codes is that the “G” stands for “geometry” and 
tells the machines how to move the tool. While M Codes are often referred to as “miscellaneous” or “auxiliary” codes that tell the machine when to stop, start and perform other non-cutting functions.
- G Codes control: Directions for active movement and cutting
- M Codes control: Non-geometric commands to stop/start, turn on/off auxiliary, make changes in tooling

## The RoboRot CLI interface

- The commands are executed line by line.
- The input prompt is '>' and the text chars are entered here until the final [Return]
- Comments, starting with a semikolon ';' and lasting to the end of the line,
and empty lines will be ignored by the GCode-processor.
- To optimize the input of multiple-same commands there is the possibility to define a prefix:
  - When a text is entered and a underline char '_' is the last char, then the text is not interpreted as command, but it will set the prefix.
  - The prefix from now on will be put before every entered text, and will be processed together with the text
  - To undefine the prefix, use the underline char '_' as first character.
  - see the following sample:
- ```
  >;This is a comment and will be ignored
  >G100 P0 S24 F100
  >G100 _;Set a prefix
  >G100 ;This is the prompt already filled with the prefix
  >G100 P0 S24 F100 P1 S-24 F200
  >G100 _;Will remove the prefix ('G100 ' was the old prefix)
  >
  ```

## Overview of RoboRot G-Code commands

* ```M400``` Power-On-Self-Test (POST)
* ```M401``` Stop Power-On-Self-Test

## Further Resources

- [GCODE MCODE for Robotic Arms](https://chatgpt.com/share/66f2a865-703c-8012-be7e-3bdedb69f0bc)
- [G-Code and M-Code List](https://www.cnccookbook.com/g-code-m-code-command-list-cnc-mills/)

## References

- [G and M Codes: Everything You Need to Know - Moseys Production Machinists](https://moseys.com/the-ultimate-guide-to-g-and-m-codes)
- [G & M Code Reference Manual - MachMotion](https://machmotion.com/downloads/GCode/Mach4-G-and-M-Code-Reference-Manual.pdf)
- [The NIST RS274NGC Interpreter](https://tsapps.nist.gov/publication/get_pdf.cfm?pub_id=823374)