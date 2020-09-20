add_library(dp_lib STATIC
    abstractions/Product.hpp
    abstractions/Product.cpp
    abstractions/StatisticTool.hpp
    abstractions/StatisticTool.cpp

    creational/Builder.hpp
    creational/Builder.cpp
    creational/Director.hpp
    creational/Director.cpp
    creational/FactoryMethod.hpp
    creational/FactoryMethod.cpp
    creational/Prototype.hpp
    creational/Prototype.cpp

    structural/Adapter.cpp
    structural/Adapter.hpp
    structural/Bridge.cpp
    structural/Bridge.hpp
    structural/BridgeImplConcrete.hpp
    structural/BridgeImplConcrete.cpp
    structural/BridgeImpl.hpp
    structural/Flyweight.cpp
    structural/Flyweight.hpp

    behavioral/Chain.hpp
    behavioral/Chain.cpp
    behavioral/ChainMy.hpp
    behavioral/ChainMy.cpp
    behavioral/Command.hpp
    behavioral/Command.cpp

    algorithms/TwoSum.hpp
    algorithms/FindLongestString.hpp
    algorithms/General.hpp

    concurr/Hello.cpp
    concurr/Hello.hpp
    )

target_compile_options(dp_lib
   PUBLIC
    -g -Wall
   PRIVATE
    -fPIC)

target_link_libraries(dp_lib
    PRIVATE
        Threads::Threads
    )

#add_static_tools(dp_lib)
target_compile_features(dp_lib
    PRIVATE
        cxx_std_17)

target_include_directories(dp_lib
    PUBLIC
        creational
        abstractions
        structural
        behavioral
        algorithms
        concurr)
