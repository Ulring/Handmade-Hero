@echo off

REM To add this shortcut in cmd:
REM %windir%\system32\cmd.exe /k C:\Users\Anass\Desktop\work\handmade\misc\shell.bat 

call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall" x64
set path=C:\Users\Anass\Desktop\work\handmade\misc:%path%
