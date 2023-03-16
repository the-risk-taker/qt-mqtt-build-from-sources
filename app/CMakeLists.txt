add_executable(app-using-mqtt
    main.cpp
)

target_link_libraries(app-using-mqtt
    PRIVATE Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Mqtt
)
