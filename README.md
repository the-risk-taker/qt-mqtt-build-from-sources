# Qt MQTT build from sources

Qt MQTT does not come with standard Qt installation, some manual building from sources are required. This guide will go through the process.

- [Requirements](#requirements)
- [Building for Desktop](#building-for-desktop)
  - [With QtCreator](#with-qtcreator)
  - [With CMake for Qt6 from command line](#with-cmake-for-qt6-from-command-line)
- [Building for Android](#building-for-android)
- [Validate](#validate)

> [!NOTE]
> Tested under MinGW + Qt5 (Windows), MSVC + Qt6 (Windows) and GCC + Qt6 (Linux).

## Requirements

To build Qt MQTT from sources, you will need the following:

- CMake
- Qt MQTT sources
- Toolchain for your platform
- Perl (Windows only)

**CMake**

You can use your own, or install `CMake` from the Qt Maintenance Tool.

**Qt MQTT source**

You can download the `Qt MQTT sources` from online [repository](https://code.qt.io/cgit/qt/qtmqtt.git/) or you can download them along with the current version of Qt (if they are distributed) from the Qt Maintenance Tool by checking `Sources` checkbox.

> [!IMPORTANT]
> Remember to checkout to tag corresponding to the version of Qt you are using.

**Toolchain**

The Toolchain depends on your platform, for example, MSVC for Windows, GCC or Clang for Linux, etc. You need them installed.

**Perl (Windows only)**

To download `Perl` for Windows, go to <https://strawberryperl.com/>. After installing Perl, you will need to create an environment variable called `HOST_PERL` with the path to the Perl executable. For example: `HOST_PERL=C:\Perl\Strawberry\perl\bin\perl.exe`.

## Building for Desktop

### With QtCreator

The easiest way to build the module is to open `CMakeLists.txt` (Qt6) or `qtmqtt.pro` (Qt5) - project from downloaded `qtmqtt` sources directory with QtCreator. To build with Qt Creator, setup the project for your platform and build library.

After a successful build, you can install the library by going to the `build` directory (check the Qt Creator `Compile Output` to find the directory) and running the following command in the shell:

```shell
# when built with CMake
cmake --install . --verbose

# when built with qmake
make install
```

> [!TIP]
> If you don't have CMake or qmake in path, you can use CMake/qmake installed with Qt. You can check QtCreator logs to find CMake path.

### With CMake for Qt6 from command line

Go to the root of cloned `qtmqtt` repo and run below to setup, build and install:

```shell
cmake -S . -B build -DCMAKE_PREFIX_PATH=/home/mateusz/Qt/6.8.1/gcc_64 -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
cmake --build build --target install
```

> [!IMPORTANT]
> Ensure you provide a valid path to your Qt version toolchain in `CMAKE_PREFIX_PATH`.

## Building for Android

Before building for Android, make sure your Android toolchain works by compiling and running template project on the Android platform. Then, build and install the library as described above using `QtCreator`. Make sure that in the logs, you will see:

```plaintext
[19/19 4.0/sec] Linking CXX shared library lib\libQt6Mqtt_arm64-v8a.so
```

> [!TIP]
> If you get the error `...androiddeployqt.exe" exited with code 2` when building the library, it's fine. The library is already built.

## Validate

After successful build and installation, check if executable from `app/` builds and works by opening the `CMakeLists.txt` in QtCreator and building the project.
