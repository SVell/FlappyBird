cmake_minimum_required(VERSION 3.23)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

add_executable(FlappyBird src/main.cpp src/Game.cpp src/Game.h src/TextureManager.cpp src/TextureManager.h src/Constants.h src/GameObject.cpp src/GameObject.h src/Vector2.h src/Player.cpp src/Player.h src/MovingObject.cpp src/MovingObject.h src/Collision.cpp src/Collision.h)

target_link_libraries(FlappyBird ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -mwindows)
