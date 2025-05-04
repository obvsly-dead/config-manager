add_executable(config_server
    ConfigurationManager.cpp
    main.cpp
)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_link_libraries(config_server PRIVATE Qt5::Core Qt5::DBus nlohmann_json::nlohmann_json)
