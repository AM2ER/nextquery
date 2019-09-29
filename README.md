## NextQuery

Udacity C++ nanodegree Capstone project

## Functionality

Next query is a command line tool that searches on mainstream search engines for the keywords passed in as arguments and
shows in them in the command line.

Supported search engines are: google, bing.

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

- sudo apt install libcurl3
- sudo apt install libpoco-dev
- sudo apt-get install openssl libssl-dev

## Basic Build Instructions

1. Clone this repo
2. cd in to the root folder and clone googletest : 
    git clone https://github.com/google/googletest.git
3. Make a build directory in the top level directory: `mkdir build && cd build`
4. Compile: `cmake .. && make`
5. Run it for search: `./NextQuery <keywords to search space separated>`
6. Run it with search history: `./NextQuery -h`

## File Structure
```
.
├── bin 
├── CMakeLists.txt
├── config
├── curlpp
├── googletest
├── README.md
├── src
└── test
```

- bin : where the binary of the application will be built [has to be created]
- CMakeLists.txt : root cmake file that defines project build requirements
- config: header configuration files used by CMakeLists.txt for major and minor application version
- curlpp : curlpp source code for project build dependencies
- googletest : googletest source code for project test requirements
- READE.md : this file
- src: folder containing source header and associated implementation files for the binary
- test: folder containing the unit test for testing different classes written for the project

## Expected behaviour

Once the application is built and called, for example like this:

./NextQuery android

The out should be a list of results coming from Google and Bing showing the first results of each
search engine for the keyword android.

Example:

bing :: Applications Android gratuites - commentcamarche.net
https://www.commentcamarche.net/download/android/

bing :: Smartphones Android - Achetez un t&#233;l&#233;phone Android pas cher
https://www.meilleurmobile.com/mobiles/search.do?osName=android

google :: Android - FrAndroid
https://fr.wikipedia.org/wiki/Android

## Rubric criteria

## Compiling and Testing

### The submission must compile and run

- create a bin directory in project source
- cd in to bin directory
- run cmake .. & make

## Loops, Functions, I/O

###The project demonstrates an understanding of C++ functions and control structures

#### while / for / if/else
    
- HtmlParser.cpp : line 22, use of while loop
- HtmlParser.cpp : line 59, use of for loop
- UrlBuilder.cpp : line 27-37, use of if/else structure
- GoogleHtmlParser.cpp | BingHtmlParser.cpp : code organized in functions

### The project reads data from a file and process the data, or the program writes data to a file.

- NextQuery.cpp : line 57 and 74, read and writing

### The project accepts user input and processes the input.

- NextQuery.cpp : line 13 - 52, read and process user input params

## Object Oriented Programming

### The project uses Object Oriented Programming techniques.

- see source code in src directory

### Classes use appropriate access specifiers for class members.

- HtmlParser.h : line 18 & line 29 public and private access specifiers

### Classes abstract implementation details from their interfaces.

- QueryRunner.h : abstracts away the execution of a web search and hides multi-threading

### Classes follow an appropriate inheritance hierarchy.

- UrlBuilder.h and HtmlParser.h extends AbstractBase.h for common functionality

### Derived class functions override virtual base class functions.

- BingHtmlParser.h and GoogleHtmlParser.h implement virtual methods from HtmlParser.h

## Memory Management

### The project uses smart pointers instead of raw pointers.

- QueryRunner.cpp uses unique_ptr, line 18 for parser strategy
- QueryRunner.h uses shared_ptr, line 25 for grouping results from 2 threads

## Concurrency

### The project uses multithreading.

- QueryRunner.cpp : line 43, use of multi-threading

### A mutex or lock is used in the project.

- QueryRunner.cpp : line 31, lock gard is used