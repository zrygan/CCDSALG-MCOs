REM By: Zhean Ganituen (zrygan)
REM Batch file to delete all files in _out
REM For MCO2

@echo off

REM Clear Screen
cls

REM Change directory to the folder where files are located
cd _out

REM Delete all files in the folder
del /Q *

REM Optional: Display a message after deletion
echo All files deleted.
