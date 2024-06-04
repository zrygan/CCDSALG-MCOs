REM By: Zhean Ganituen (zrygan)
REM Batch file to execute C file using I/O redirection 

REM Clear Screen

cls

REM Compile `main.c` using `gcc -Wall`

gcc -Wall main.c -o main.exe

REM Use I/O file redirection

TESTCASE.txt < main > RESULT.txt

REM END OF FILE