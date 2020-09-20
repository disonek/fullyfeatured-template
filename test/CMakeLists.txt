add_executable(dp_re_tests
    creational/BuilderTest.cpp
    creational/FactoryMethodTest.cpp
    creational/PrototypeTest.cpp

    utils/TypeDeductionTest.cpp
    utils/TypeDeduction.hpp
    utils/Utils.hpp

    structural/AdapterTest.cpp
    structural/BridgeTest.cpp
    structural/FlyweightTest.cpp

    behavioral/ChainTest.cpp
    behavioral/CommandTest.cpp

    algorithms/LeetCodeTest.cpp
    algorithms/StandardTest.cpp
    )

target_include_directories(dp_re_tests
    PRIVATE 
        utils)


        
target_link_libraries(dp_re_tests
    PRIVATE
    CONAN_PKG::gtest
    Threads::Threads
    CONAN_PKG::boost
    dp_lib
    )

set_property(TARGET dp_re_tests PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

target_compile_options(dp_re_tests
   PRIVATE
    -g -Wall -fPIC)

add_test(NAME dp_re_tests
         COMMAND dp_re_tests)

# add_custom_command(TARGET dp_re_tests
#                    POST_BUILD
#                    COMMAND ctest -C Debug -T test --output-on-failuret)
