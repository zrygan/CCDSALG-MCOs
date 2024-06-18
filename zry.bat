REM By: Zhean Ganituen (zrygan)
REM Batch file to execute C file using I/O redirection 

echo off

REM Clear Screen

cls

REM Compile `main.c` using `gcc -Wall`

gcc -Wall main.c stack.c queue.c evalPost.c inToPost.c -o main.exe

REM Without I/O file redirection

REM main

REM With I/O file redirection

main.exe < TESTCASE_1.txt > RESULT_1.txt
main.exe < TESTCASE_2.txt > RESULT_2.txt

REM END OF FILE