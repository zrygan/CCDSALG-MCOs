REM By: Zhean Ganituen (zrygan)
REM Batch file to execute C file using I/O redirection 

echo off

REM Clear Screen
cls

REM Compile mco1
REM gcc -Wall src/mco1/*.c -o main_mco1.exe

REM Compile mco2
gcc -Wall src/mco2/*.c -o main_mco2.exe

REM Execute without I/O redirection

REM MCO1
REM main_mco1.exe

REM MCO2 (use test/mco2/graph.txt as File Name)
main_mco2.exe

REM Execute mco1 with input redirection and output redirection
REM type test\mco1\TESTCASE_1.txt | main_mco1.exe > test\mco1\RESULT_1.txt
REM type test\mco1\TESTCASE_2.txt | main_mco1.exe > test\mco1\RESULT_2.txt

REM Execute mco2 with input redirection and output redirection (if needed)
REM type test\mco2\TESTCASE_1.txt | main_mco1.exe > test\mco2\RESULT_1.txt
REM type test\mco2\TESTCASE_2.txt | main_mco1.exe > test\mco2\RESULT_2.txt

REM END OF FILE
