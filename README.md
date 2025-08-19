
# Instruction-code-converter

## Overview
This project is a C++ program that converts assembly-like instructions (e.g., ADD, STA, INP) into binary machine code based on a custom instruction set architecture. It reads instructions from `input.txt` and writes the converted binary codes to `output.txt`.

## Features
- Supports multiple instruction sets and operand types
- Handles direct and indirect addressing
- Skips comments in the input
- Outputs both the original instruction and its binary representation

## How to Build
1. Make sure you have a C++ compiler (e.g., g++, clang++) installed.
2. Compile the program:
	 ```sh
	 g++ converter.cpp -o converter
	 ```
	 On Windows, you can use MinGW or Visual Studio's compiler.

## How to Run
1. Place your instructions in `input.txt` (see example below).
2. Run the program:
	 ```sh
	 ./converter
	 ```
	 or on Windows:
	 ```sh
	 converter.exe
	 ```
3. The output will be written to `output.txt`.

## Input File Format (`input.txt`)
- Each line contains an instruction, optional operand, and optional comment (starting with `//`).
- Example:
	```
	ORG 20A
	BSA 103 //comment1
	INP
	ADD K
	ADD y
	ISZ x //comment2
	STA z
	ISZ 515 I
	ISZ 103
	AND 155 I //comment3
	BUN FAE I
	HLT //comment4
	x 053 //comment5
	y FE9
	z AA0
	FAFA //comment6
	FAFA
	```

## Output File Format (`output.txt`)
- Each line contains the memory address, instruction, operand, and the binary code (16 bits).
- Example output:
	```
	20A : BSA 103   0000000100000011
	...
	```

## License
This project is open source. See the original repository for details.
