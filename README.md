# PlugIN SDK

## Build

### Prerequisites
Install following dependency: `cmake -> version:3.23`, `g++`, `make`

For example in debian:
```bash
# install g++, make
sudo apt-get install g++ make

# install cmake 3.23
wget https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-linux-x86_64.tar.gz
tar -xf cmake-3.23.2-linux-x86_64.tar.gz && cp -r cmake-3.23.2-linux-x86_64/* /usr
```

### Build
```bash
## Configuration Stage
make -S . -B build -DCMAKE_BUILD_TYPE=debug

# Build Stage
cmake --build build
## clean first and build 
cmake --build build --clean-first
## clean only
cmake --build build --target clean 
```

## Docker build
```bash
# build x86 platform
sudo docker build -f Dockerfile.x86_64 .

# build jetson platform
sudo docker build -f Dockerfile.jetson .

# deploy binary, just use -o and binary will deploy to OUTPUT_DIRECTORY 
sudo docker build -f Dockerfile.x86_64 -o OUTPUT_DIRECTORY .
```
