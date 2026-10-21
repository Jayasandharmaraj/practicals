C++ OOP LAB MANUAL - SEPARATE SOURCE FILES

Programs 01 to 12: each is a standalone .cpp file. Open one file at a time in VS Code and compile it with g++.
Example (replace filename):
  g++ -std=c++17 01_university_management.cpp -o program
  ./program

For Program 10 (threads), use:
  g++ -std=c++17 10_producer_consumer.cpp -pthread -o program

Program 13 uses C++20 modules and requires a compiler/toolchain with C++20 module support. It is split into 13_main.cpp and 13_pipeline.cppm; module support varies by GCC/Clang version, so it may need a suitable CMake/compiler setup.

Note: Programs are provided as separate source files based on the lab manual's 13 experiments. Benchmark times and output ordering for threaded programs can vary by machine/run.
