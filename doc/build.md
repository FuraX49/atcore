# Building And Deploying %AtCore
Building %AtCore is broken up into to main steps Configuration and Building. Deploying %AtCore is also covered here.

## Configuration 
In order to configure your build you will need [cmake] and [extra-cmake-modules]. 

%AtCore Build Options Are: 
 - -DBUILD_GUI = ( ON | OFF )  Build the test client (Default is OFF)
 - -DBUILD_DOCS = (ON | OFF ) Build the Documentation (Default is OFF)
 - -DBUILD_TESTS = ( ON | OFF ) Build and Run Unittests (Default is OFF)

Recommended CMake Command

Linux
```
cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL+LIBDIR=lib CMakeLists.txt
```

Mac OS/ Windows
```
cmake CMakeLists.txt
```
## Building
After Configuring you Should be able to run make to build all targets.

```
make
```

## Dependencies
In addition to a working development enviroment for your system you will need the following to build %AtCore
 - qt5-base
 - qt5-serialport

Building atcore-gui adds the following dependencies:
 - qt5-widgets
 - qt5-charts
 
Building The Documentation adds the following dependency:
 - [doxygen]

### Installing Dependencies on Windows and Mac OS

#### Mac Os
Mac Os users could use [homebrew] to install both cmake and cmake-extra-modules using.
```
brew update
brew install cmake
brew tap KDE-mac/kde;
brew install kf5-extra-cmake-modules
```
Then can download and install [Qt]

#### Windows
Windows users could install [chocolatey] and do something like 
```
choco install cmake
choco install ninja
git clone -q git://anongit.kde.org/extra-cmake-modules.git
cd extra-cmake-modules
cmake -G "Ninja" . -DCMAKE_INSTALL_PREFIX= <CMAKE_INSTALL_ROOT>
ninja install
```
Then Download and install [Qt]

## Deploying %AtCore
After you build you may wish to deploy atcore on your system for use
### Linux
From the build dir the command below to install atcore with its plugins to the system (assuming cmake used above)
```
sudo make install
```
### Windows/Mac OS
On these systems atcore will look in the path of the program using it for firmware plugins 

On Windows This is in a directory next to the program
```
C:\atcore_test_GUI\atcore-gui.exe
C:\atcore_test_GUI\AtCore.dll
C:\atcore_test_GUI\plugins\repetier.dll
```

On Mac Os This is In the app Bundle 
```
atcore-gui.app/Contents/MacOS/atcore-gui
atcore-gui.app/Contents/MacOS/AtCore.dylib
atcore-gui.app/Contents/MacOS/plugins/repetier.dylib
```
[Qt]:https://www.qt.io
[doxygen]:http://www.stack.nl/~dimitri/doxygen/
[cmake]:https://cmake.org/
[extra-cmake-modules]:https://cgit.kde.org/extra-cmake-modules.git/tree
[homebrew]:https://brew.sh/
[chocolatey]:https://chocolatey.org/