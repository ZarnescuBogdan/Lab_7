cmake_minimum_required(VERSION 3.21)
project(Lab_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_7 main.cpp Domain/Entity.cpp Domain/Entity.h Repo/Repo.cpp Repo/Repo.h Tests/tests.h Tests/tests.cpp Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h)
