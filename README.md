# Qt MQTT build from sources

> Tested under MinGW + Qt5, and MSVC + Qt6

## Requirements

To build Qt MQTT from sources, you will need the following:

- CMake
- Toolchain for your specific platform
- Qt MQTT sources
- Perl (at least for Windows)

You can download the `Qt MQTT sources` from online [repository](https://code.qt.io/cgit/qt/qtmqtt.git/) or you can download them along with the current version of Qt (if are distributed) from the Qt Maintenance Tool by checking `Sources` checkbox.

You can also download `CMake` from the Qt Maintenance Tool.

To download `Perl` for Windows, go to <https://strawberryperl.com/>. After installing Perl, you will need to create an environment variable called `HOST_PERL` with the path to the Perl executable. For example: `HOST_PERL C:\Perl\Strawberry\perl\bin\perl.exe`.

The `Toolchain` will depend on your platform, for example, MSVC for Windows, GCC or Clang for Linux, etc.

## Building the Qt MQTT module with CMake (Qt6) or qmake (Qt5)

The easiest way to build the module is to open `CMakeLists.txt` (in case of Qt6) or `qtmqtt.pro` (in case of Qt5) project for `qtmqtt` sources directory in QtCreator that can be found in the Qt installation directory or downloaded repository -- `remember to checkout to tag` which correspond to yours installed Qt version. To build with Qt Creator, choose your target platform (using the specific toolchain).

After a successful build, you can install the library by going to the `build` directory (check the Qt Creator Compile Output to find the directory) and running the following command in the shell:

```shell
# when built with CMake
cmake --install . --verbose

# when built with qmake
make install
```

> NOTE: If you don't have CMake in path, you can use CMake installed with Qt. You can check QtCreator logs to find CMake path, for example: `C:\Qt\Tools\CMake_64\bin\cmake.exe --install . --verbose`. This command will install the library in the desired directories.

## Run example project

After successful build and installation, check if `TestQtMQTT` builds and works.

## Building for Android

Before building for Android, make sure your Android toolchain works by compiling and running an example app on the Android platform. Then, build the library as described above (including the install step). Make sure that in the logs, you will see:

```plaintext
[19/19 4.0/sec] Linking CXX shared library lib\libQt6Mqtt_arm64-v8a.so
```

> NOTE: If you get the error .`..androiddeployqt.exe" exited with code 2` when building the library, it's fine. The library is already built.
