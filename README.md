# Conversor
This conversor will convert any number from binary to the 36th base. The representations are: 0-9 then A-Z.

Number|Representation|
-|-|
0-9|0-9
10-35|A-Z
## Usage
After compiling the program and executing a prompt will appear. You should put the values on the required order, which is: `number`, `it's base` and the convertion base. Like the example below:

    Put values with the following syntax: [[number], [its base], [convert to]]: 1010 2 10
As you can see, it will convert the value **1010<sub>2</sub>** to decimal, which is: **10<sub>10</sub>**. The output you should see is:

    The chosen number (1010)2 was converted!
    it's equals to (10)10
## Compiling
You can use any IDE in order to compile the code, however it should have the following libraries in order to include:
- stdio.h
- string.h
> Note that this project will not run on GNU/Linux because the default `string.h` library doesn't come with the function `strrev()`.
