@echo off

set EXE_DIR=%~dp0bin\WriteTool\Release\WriteTool.exe
set QT_BIN_DIR=D:\SDK\qt\6.8.0\msvc2019_64\bin

if exist %EXE_DIR% (
    echo FOUND EXE SUCCESS
)else (
    echo NOT FOUND EXE:%EXE_DIR%
	exit 0
)

set QT_WIN_DEV=%QT_BIN_DIR%\windeployqt.exe
if exist %QT_WIN_DEV% (
	echo FOUND QT SUCCESS
)else (
	echo NOT FOUND EXE:%EXE_DIR%
	exit 0
)

%QT_WIN_DEV% %EXE_DIR%
echo FIND DEPENDS FINISHED!

pause