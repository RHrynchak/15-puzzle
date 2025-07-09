cmake_minimum_required(VERSION 3.8.0)

# Set architecture before project() - this is crucial
set(CMAKE_GENERATOR_PLATFORM x64)

project(15puzzle VERSION 0.1.0 LANGUAGES C CXX)

if (MSVC)
    add_compile_options(/W3)
    add_compile_options(/std:c++20)
    add_compile_options(/EHsc)
    add_compile_options(/MT)
else()
    add_compile_options(-Wall)
    add_compile_options(-std=c++20)
    add_compile_options(-fexceptions)
endif()

# Set the SDL3 directory
set(SDL3_DIR "C:/Users/Роман/OneDrive/Робочий стіл/проги/libraries/SDL3-3.2.16/cmake")
#set(SDL3_image_DIR "C:/Users/Роман/OneDrive/Робочий стіл/проги/libraries/SDL3_image-3.2.4/cmake")
set(SDL3_ttf_DIR "C:/Users/Роман/OneDrive/Робочий стіл/проги/libraries/SDL3_ttf-3.2.2/cmake")

# Find SDL3
find_package(SDL3 REQUIRED CONFIG)
#find_package(SDL3_image REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

add_executable(15puzzle main.cpp tile.cpp board.cpp direction.cpp point.cpp)

# Link SDL3 - check which targets are available
if(TARGET SDL3::SDL3-shared)
    target_link_libraries(15puzzle SDL3::SDL3-shared)
    message(STATUS "Using SDL3::SDL3-shared")
elseif(TARGET SDL3::SDL3)
    target_link_libraries(15puzzle SDL3::SDL3)
    message(STATUS "Using SDL3::SDL3")
endif()

# Link SDL3_image - check which targets are available
#if(TARGET SDL3_image::SDL3_image-shared)
#    target_link_libraries(15puzzle SDL3_image::SDL3_image-shared)
#    message(STATUS "Using SDL3_image::SDL3_image-shared")
#elseif(TARGET SDL3_image::SDL3_image)
#    target_link_libraries(15puzzle SDL3_image::SDL3_image)
#    message(STATUS "Using SDL3_image::SDL3_image")
#endif()

# Link SDL3_ttf - check which targets are available
if(TARGET SDL3_ttf::SDL3_ttf-shared)
    target_link_libraries(15puzzle SDL3_ttf::SDL3_ttf-shared)
    message(STATUS "Using SDL3_ttf::SDL3_ttf-shared")
elseif(TARGET SDL3_ttf::SDL3_ttf)
    target_link_libraries(15puzzle SDL3_ttf::SDL3_ttf)
    message(STATUS "Using SDL3_ttf::SDL3_ttf")
endif()

# Handle SDL3main separately
if(TARGET SDL3::SDL3main)
    target_link_libraries(15puzzle SDL3::SDL3main)
    message(STATUS "Using SDL3::SDL3main")
elseif(WIN32)
    # On Windows, we might need to link main manually
    find_library(SDL3_MAIN_LIB NAMES SDL3main PATHS ${SDL3_DIR}/../lib NO_DEFAULT_PATH)
    if(SDL3_MAIN_LIB)
        target_link_libraries(15puzzle ${SDL3_MAIN_LIB})
        message(STATUS "Using manual SDL3main: ${SDL3_MAIN_LIB}")
    endif()
endif()

# Static runtime linking for MSVC (to avoid needing MSVC redistributable)
if(MSVC)
    set_target_properties(15puzzle PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
    )
endif()

# Copy SDL3 DLL to output directory on Windows
if(WIN32)
    add_custom_command(TARGET 15puzzle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:15puzzle>
    )
    #add_custom_command(TARGET 15puzzle POST_BUILD
    #    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    #    $<TARGET_FILE:SDL3_image::SDL3_image>
    #    $<TARGET_FILE_DIR:15puzzle>
    #)
    add_custom_command(TARGET 15puzzle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3_ttf::SDL3_ttf>
        $<TARGET_FILE_DIR:15puzzle>
    )
endif()