# Digital IC Tester

## Introduction

The Digital IC Tester is an electronic project based on the Arduino Board, which is used to segregate and test basic logic gate ICs belonging to the 74xx Series. The Tester sends certain signals to test the functionality of the IC, and gives an output on the LCD screen attached to the Board. The Project is in the form of an arduino shield, or a Tester board which can sit on top of the arduino board.

###The Following IC's are Supported :  

IC 7408/7409 - AND GATE  
IC 7432 - OR GATE  
IC 7400/7401/7403 - NAND GATE  
IC 7402 - NOR GATE  
IC 7486 - XOR GATE  
IC 74266/72810 - XNOR GATE  

## Working

The 4 outputs of the IC's can be used to check the outputs of each test cases in a Truth table. The Input Pairs can be loaded in as per the Pin numbers on the IC.  

Pin    Value  
1   -   0  
2   -   0  
4   -  0  
5   -  1  
7   -  Vcc  
9   -  1  
10  -  0  
12  -  1  
13  -  1  
14  -  Gnd  

The pins 7 and 14 act as the Voltage input and Ground for the entire 74xx IC series.   

*Dev Notes*  
The Schematics of the project will be uploaded soon. The code is completely functional.  
More Documentation will be added about the project explaining certain parts of the code.  