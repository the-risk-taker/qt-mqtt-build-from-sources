cmake_minimum_required(VERSION 3.16)

project(TestQtMQTT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 COMPONENTS Quick Mqtt REQUIRED)

qt_add_executable(appTestQtMQTT
    main.cpp
)

target_link_libraries(appTestQtMQTT
    PRIVATE Qt6::Quick Qt6::Mqtt
)

install(TARGETS appTestQtMQTT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
