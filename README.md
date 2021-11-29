# Operating-Systems-Programming-Assignment-2
In this assignment, we had to take data in from an input file, and perform the banker's algorithm on it.

# Getting Started
In order to run this program follow these steps.

## Prerequisites 
  - Compiled on Ubuntu 20.04.3
  - g++
```bash
sudo apt-get install g++
```
## Installation
  - 1. Clone the repo 
``` bash 
URL:
```

## To Run the Code for Yourself
  - 1. Use g++ to Compile the Program
  ```bash
  g++ Banker.c -o Banker
  ```
   - 2. To Run the Program
  ```bash
  ./producer & ./consumer &
  ```
  
  ## Output
  The output should be:
  ```bash
  The system is in a safe state.
  The following is the safe sequence:
   P1 -> P3 -> P4 -> P0 -> P2
   ```
## Code Written by
- Joshua Friedman

## Built Using
 - Visual Sutdio Code 1.62 - programming environment
 - g++ 9.3.0 - compilation
 - Ubuntu 20.04.3 - operating system
 
 ## Acknowledgements
 - Dr. Qiang Guan - My operating systems professor
 - URL: https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/
 - URL: https://www.youtube.com/watch?v=BQoE-nkN8XQ
