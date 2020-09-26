add_executable(dp_re_tests)
target_sources(
  dp_re_tests
  PUBLIC creational/BuilderTest.cpp
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
         algorithms/StandardTest.cpp)

target_include_directories(dp_re_tests PRIVATE utils)

target_link_libraries(
  dp_re_tests
  PRIVATE project_options
          project_warnings
          CONAN_PKG::gtest
          Threads::Threads
          CONAN_PKG::boost
          dp_lib)

add_test(NAME dp_re_tests COMMAND dp_re_tests)

add_custom_command(
  TARGET dp_re_tests
  POST_BUILD
  COMMAND ctest -C Debug -T test --output-on-failuret)
