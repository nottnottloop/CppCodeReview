cmake_minimum_required(VERSION 3.12)

project(project)
add_executable(game src/main.cpp src/collision.cpp src/rect.cpp src/window.cpp)

include_directories(C:/dev/Libraries/SDL2-2.0.16/include C:/dev/vcpkg/installed/x64-windows/include include)
target_link_directories(game PUBLIC C:/dev/Libraries/SDL2-2.0.16/lib/x64 C:/dev/vcpkg/installed/x64-windows/bin)

target_link_libraries(game SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)