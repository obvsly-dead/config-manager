add_executable(conf_manager_app
    ConfManagerApplication.cpp
    main.cpp
)

target_link_libraries(conf_manager_app PRIVATE Qt5::Core Qt5::DBus)
