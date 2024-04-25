@echo on

set SDK_DIR=D:/SDK
set QT_DIR=%SDK_DIR%/qt/6.8.0/msvc2019_64
set CMAKE_DIR=D:/cmake/cmake-3.23.2-windows-i386/cmake-3.23.2-windows-i386/bin

mkdir build
mkdir install

set PATH=%PATH%;%QT_DIR%/bin

%CMAKE_DIR%/cmake.exe -S . -B build ^
 -DQT6_DIR=%QT_DIR%  ^
 -DCMAKE_INSTALL_PREFIX=install ^
 -G"Visual Studio 17 2022"

echo build finish!

::%CMAKE_DIR%/cmake.exe --build build --config Release --target install

::pause