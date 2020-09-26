add_executable(app)

target_sources(dp_lib PRIVATE main.cpp)

target_link_libraries(app PRIVATE project_options project_warnings dp_lib)
