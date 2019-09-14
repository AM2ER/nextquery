## NextQuery

Capstone project following the Udacity C++ nanodegree

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Dependencies to install

sudo apt install libcurl3
sudo apt install libpoco-dev
sudo apt-get install openssl libssl-dev

## Basic Build Instructions

1. Clone this repo
2. cd in to the root folder and clone googletest : 
    git clone https://github.com/google/googletest.git
3. Make a build directory in the top level directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`
5. Run it: `./NextQuery <keywords to search space separated>`.

