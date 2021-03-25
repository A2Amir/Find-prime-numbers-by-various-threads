# Find prime numbers by various threads

##### A multi-threaded C program to find prime numbers between two ranges and the time it takes the program to run.


* Step 1.Use the Atom editor to save the C source code on your laptop. Change the variables below in the code to what you want.
                         
                         NUM1    0
                         NUM2    15
                         NUMOFTHREADS    8
                         
* Step 2.Compile the program. Type the command 

            gcc -g -o prime prime.c -lpthread

    This command will invoke the GNU C compiler to compile the file **prime.c** and output (-o) the result to an executable called prime.

*  Step 3.Execute the program. Type the command

            ./prime 
