## CMake  
Set up CMakeLists.txt to generate build files.  
## Install C++  
Since I don't have C++ installed in my environment I have to install it.  
    run $ sudo apt-get update && sudo apt-get install build-essential  
## Building my first project  
After creating a simple hello world program in ./src/main.cpp we can run  
    \$ cmake -S . -B build/  
This configures the project using our CMakeLists file and generates the build files in the build/ directory. Next we can run:  
    \$ cmake --build build/  
and  
    \$ ./build/hydro  
to see our output  
    Hello World!  


