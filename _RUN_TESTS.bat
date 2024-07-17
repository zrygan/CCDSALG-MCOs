REM By: Zhean Ganituen (zrygan)
REM Batch file to execute C file with I/O redirection
REM For MCO2

echo off

REM Clear Screen
cls

REM Compile mco2
gcc -Wall src/mco2/*.c -o main_mco2.exe


REM Run I/O Redirection with test files
cd _in

REM Test case 1
..\main_mco2.exe < 1_test_in.txt > ..\_out\1_test_out.txt

REM Test case 2
..\main_mco2.exe < 2_test_in.txt > ..\_out\2_test_out.txt

REM Test case 3
..\main_mco2.exe < 3_test_in.txt > ..\_out\3_test_out.txt

REM Test case 4
..\main_mco2.exe < 4_test_in.txt > ..\_out\4_test_out.txt

cd ..
