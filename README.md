# CCDSALG-MCOs

Repository for CCDSALG (Data Structures and Algorithms) course projects at De La Salle Univerity.

Balcita, V., [Ganituen, Z.](github.com/zrygan), and Jimenez, J.
2024

## How To

1. Simply clone the repository via: `https://github.com/zrygan/CCDSALG-MCOs.git`
2. Using the command line, go to the directory location of the main file `main.c`.
3. Execute the main file.
   1. Using `bat` file:
      1. Run the command `zry`.
   2. Using `gcc -Wall` and I/O redirection separately:
      1. Run `gcc -Wall main.c <...>` (remember to include all `.c` files here)
      2. Run `TESTCASE.txt < a > RESULT.TXT`

## Files and Directories

1. `main.c`: contains the main method
2. `queue.c` and `queue.h`: the source and header files for the queue data structure (PART 1).
3. `stack.c` and `stack.h`: the source and header files for the stack data structure (PART 1).
4. `inToPost.c`: infix to postfix algorithm source file.
5. `evalPost.c`: evaluate postfix algorithm source file.
6. `TEXTCASE.txt`: contains the test case for file I/O redirection.
7. `RESULT.txt`: contains the result of the test case for file I/O redirection.
8. `zry.bat`: batch file to combine needed command prompt commands in a single command.
9. `docs/..`: contains the specs, to-do list, and other developer documentation.
