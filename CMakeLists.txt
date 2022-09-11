# CMakeList.txt: проект CMake для tp_2_lab_1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("tp_2_lab_1")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (tp_2_lab_1 "tp_2_lab_1.cpp" "tp_2_lab_1.h" "animal.h" "fish.h" "bird.h" "cat.h" "keeper.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tp_2_lab_1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
