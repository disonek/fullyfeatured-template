add_executable(app
     main.cpp
    )
target_link_libraries(app
    PRIVATE
        dp_lib
        )
target_compile_options(app
    PUBLIC
        -g -Wall -fPIC)
