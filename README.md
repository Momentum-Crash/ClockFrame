The Driver file is used for driving the program of a clock, adding time to it via basic functions that allow users to increment the time. 
It starts off by grabbing the current system time then allows a user to add time to that system time.
Users can input 1, 2, 3, or 4 to access different functions.
Option 1, 2, and 3 access adding a second, minute, and hour respectively.
Option 4 is only used to exit the program and lets the user know first that it's ending the program.

The program was made to add two clocks to a page (either inside of a web browser or externally on a application of it's own). The program was intended to allow the user to see the current time in both 12 and 24 hour formats. The best part of the program is handling time and creating a refreshable page or screen.

The program itself is rather basic and doesn't have a whole lot of flavor to it, but it did teach me how to work with time datatypes in C++. It also taught me how to work with continually updating screens using clear for the first time. I believe that the biggest improvements to this project would be to implement a way to properly switch AM to PM and PM to AM (currently it's lacking that feature) and to allow users to input different times to adjust the clock by both going up and down. Currently the clock only increments time and doesn't have a way to decrement it.

The barebones style of the code makes the program pretty versatile for usage in other programs. The comments are easy to read making the program readable and maintable since reading through the comments tells users what the code is doing and what they can expect the code to fufill.
