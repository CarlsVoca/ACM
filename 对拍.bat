:loop
rundatas.exe
std.exe
tmp.exe
fc tmp.out std.out
if not errorlevel 1 goto loop
pause
goto loop