cmake_minimum_required(VERSION 3.8)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 11)

set(APPEARANCE_SOURCE_FILE AppearanceMode/AppearanceMode.h)
set(BUILDER_SOURCE_FILE BuilderPattern/BuilderPattern.h)
set(DECORATOR_SOURCE_FILE DecoratorPattern/Decorator.h)
set(FACTORYMETHOD_SOURCE_FILE FactoryMethodPattern/FactoryMethodPattern.h)
set(PROTOTYPE_SOURCE_FILE PrototypePattern/PrototypeBase.h)
set(APPEARANCE_SOURCE_FILE AppearanceMode/AppearanceMode.h Test/AppearanceModeTest.cpp ObserverPattern/ObserverPattern.h)
set(PROXY_SOURCE_FILE ProxyPattern/Proxy.h)
set(SIMPLEFACTORY_SOURCE_FILE SimpleFactory/FactoryInstance.h SimpleFactory/InstanceA.cpp SimpleFactory/InstanceA.h
        SimpleFactory/InstanceB.cpp SimpleFactory/InstanceB.h SimpleFactory/SimpleFactoryBase.cpp SimpleFactory/SimpleFactoryBase.h
        SimpleFactory/SimpleFactoryContext.cpp SimpleFactory/SimpleFactoryContext.h)
set(STRATEGY_SOURCE_FILE StrategyPattern/StrategyContext.cpp StrategyPattern/StrategyContext.h)
set(TEMPLATE_SOURCE_FILE TemplatePattern/TemplatePattern.h)
set(OBSERVER_SOURCE_FILE ObserverPattern/ObserverPattern.h)

add_executable(AppearanceMode ${APPEARANCE_SOURCE_FILE} Test/AppearanceModeTest.cpp)
add_executable(BuilderPattern ${BUILDER_SOURCE_FILE} Test/BuilderPatternTest.cpp.cpp)
add_executable(DecoratorPattern ${DECORATOR_SOURCE_FILE} Test/DecoratorPatternTest.cpp)
add_executable(FactoryMethodPattern ${FACTORYMETHOD_SOURCE_FILE} Test/FactoryMethodPatternTest.cpp)
add_executable(PrototypePattern ${PROTOTYPE_SOURCE_FILE} Test/PrototypePatternTest.cpp)
add_executable(ProxyPattern ${PROXY_SOURCE_FILE} Test/ProxyPatternTest.cpp)
add_executable(SimpleFactory ${SIMPLEFACTORY_SOURCE_FILE} Test/SimpleFactoryTest.cpp)
add_executable(StrategyPattern ${STRATEGY_SOURCE_FILE} Test/StrategyPatternTest.cpp)
add_executable(TemplatePattern ${TEMPLATE_SOURCE_FILE} Test/TemplatePatternTest.cpp)
add_executable(ObserverPattern ${OBSERVER_SOURCE_FILE} Test/ObserverPatternTest.cpp)