This repository is created for me or maybe to help other people :D 

What is the difference from standard C++ libraries.
Just the ease of use )

An example of how my library works:

Random(min,max); //min = 0 / 0.0f && max = 100 / 100.0f

c++14 standart library:

srand (time (NULL)); // + include ctime
std::cout << rand () % 100 + 1; 

c++20 standart library:
std::uniform_int_distribution<> distrib(0, 100);

