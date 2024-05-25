= Command Line Shell (ash)

== Team members
1. Ahmed Mohamed Afifi
	- `print-file`
	- `view-file`
	- The history class
2. Ahmed Mohamed Abdelmaboud
	- `where`
	- `print-dir`
3. Yahia Hany Gaber
	- Main shell process
	- `destroy`
	- `change-loc`
4. Mazen Ahmed Refaei
	- `clone`
	- `punch`
5. Zein Hatem Hafez
	- Built-ins (`change-dir`, `exit`)
	- `elder`

== Problem statement

A basic UNIX command line shell able to excute UNIX commands as well as a number of re-made commands in C/C++ and output results. The primary ojective of this project is to create a shell that allows basic file/directory manipulating operations.

== Implementation details

The shell process is a loop that reads commands, splits the commands into arguments, checks whether the commands are built in to the shell or external and finally excute them. How the excution process works is that the operating system stops the current process and loads the new program and waits for its termination to return back to the original process. 

== Testing and results

The shell works as expected as it passes basic tests on file creation, deletion, copying and moving as well as moving between the system's directories.
