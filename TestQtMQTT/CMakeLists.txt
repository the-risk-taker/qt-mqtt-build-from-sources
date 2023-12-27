cmake_minimum_required(VERSION 3.16)

project(TestQtMQTT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Quick Mqtt REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Quick Mqtt REQUIRED)

add_executable(appTestQtMQTT
    main.cpp
)

target_link_libraries(appTestQtMQTT
    PRIVATE Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Mqtt
)

install(TARGETS appTestQtMQTT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
