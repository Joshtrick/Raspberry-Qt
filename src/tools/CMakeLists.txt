add_executable (demo demo.cpp ../../include/mainwindow.hpp ../../include/dummyworker.hpp)

#add_executable (demo demo.cpp)
target_link_libraries (demo Raspberry-Qt)
