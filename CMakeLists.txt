cmake_minimum_required( VERSION 3.16 )

# project name
project(
    NoNameProject VERSION 0.0.1
                  LANGUAGES CXX
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- target ----
add_executable(
    serendip src/main.cpp
             src/game/game.cpp
             src/game/window.cpp
             src/game/component/entity_manager.cpp
             src/game/component/input_system.cpp
             src/game/component/player_movement_system.cpp
             src/game/component/render_system.cpp
             src/input/input.cpp
             src/object/player.cpp
             src/physics/point.cpp
             src/renderer/renderer.cpp
             src/texture/texture_manager.cpp
             src/time/timer.cpp
)

# include
target_include_directories(
    serendip PRIVATE
             include
)

include_directories(
    serendip PRIVATE
             src
             src/game
             src/game/component
             src/input
             src/object
             src/physics
             src/renderer
             src/texture
             src/time
)

# properties
set_target_properties(
    serendip PROPERTIES
             CXX_STANDARD 20
             CXX_STANDARD_REQUIRED YES
             CXX_EXTENSIONS OFF
             EXPORT_COMPILE_COMMANDS ON
)

# compiler flags
# -Weffc++            warnings from 'Effective C++' by Scott Meyers
# -Wall               more warnings
# -Wextra             more warnings
# -Wsign-conversion   enable conversions between signed and unsigned integers
# -Werror             Treat warnings as errors
# -pedantic-errors    Disable compiler extensions and confine to C++ standards
target_compile_options(
    serendip PRIVATE
             -Wall
             -Wextra
             -Weffc++
             -Wsign-conversion
             -Werror
             -pedantic-errors
)

get_property(serendip_compile_options TARGET serendip PROPERTY COMPILE_OPTIONS)
get_property(serendip_cxx_standard TARGET serendip PROPERTY CXX_STANDARD)
get_property(serendip_cxx_standard_required TARGET serendip PROPERTY CXX_STANDARD_REQUIRED)
get_property(serendip_cxx_extensions TARGET serendip PROPERTY CXX_EXTENSIONS)
get_property(serendip_export_compile_commands TARGET serendip PROPERTY EXPORT_COMPILE_COMMANDS)
message("target specific settings:")
message("  COMPILER_OPTIONS:        ${serendip_compile_options}")
message("  CXX_STANDARD:            ${serendip_cxx_standard}")
message("  CXX_STANDARD_REQUIRED:   ${serendip_cxx_standard_required}")
message("  CXX_EXTENSIONS:          ${serendip_cxx_extensions}")
message("  EXPORT_COMPILE_COMMANDS: ${serendip_export_compile_commands}")


# ---- SDL2 ----
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
target_include_directories(
    serendip SYSTEM PRIVATE
             ${SDL2_INCLUDE_DIRS}
             ${SDL2_IMAGE_INCLUDE_DIR}
)

target_link_libraries(serendip ${SDL2_LIBRARIES})
target_link_libraries(serendip ${SDL2_IMAGE_LIBRARIES})


# ----- GTest ----
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    test_serendip test/tests.cpp
)

target_link_libraries(
    test_serendip
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_serendip)

