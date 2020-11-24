cmake_minimum_required(VERSION 3.5)

project(design_patterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

find_package(Catch2 REQUIRED)

add_executable(${PROJECT_NAME}
    Behavioral/ChainOfResponsibility.cpp
    Behavioral/Command.cpp
    Behavioral/Interpreter.cpp
    Behavioral/Iterator.cpp
    Behavioral/Mediator.cpp
    Behavioral/Memento.cpp
    Behavioral/Observer.cpp
    Behavioral/State.cpp
    Behavioral/Strategy.cpp
    Behavioral/TemplateMethod.cpp
    Behavioral/Visitor.cpp
    Creational/AbstractFactory.cpp
    Creational/Builder.cpp
    Creational/FactoryMethod.cpp
    Creational/Prototype.cpp
    Creational/Singleton.cpp
    Structural/Adapter.cpp
    Structural/Bridge.cpp
    Structural/Composite.cpp
    Structural/Decorator.cpp
    Structural/Facade.cpp
    Structural/Flyweight.cpp
    Structural/Proxy.cpp
    main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ./
)

target_link_libraries(${PROJECT_NAME}
    Catch2::Catch2
)
