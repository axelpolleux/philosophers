*This project has been created as part of the 42 curriculum by apolleux*

# Description
**Philosophers** is a project of the 3rd milestone at 42 common core, meant to learn multi-threading management, concurrency control, mutual exclusion and datarace issues.

### Thread
The process execution is split into tiny sequences that can be managed independently. Unlike processes, threads share the same memory space, meaning that they can have a common variable.

### Mutex
A mutex *(mutual exclusion)*, is a part of concurrency control to prevent data race on shared resource. When two threads try to access a common property, the first thread locks the variable with a mutex, then the second thread must wait for the mutex to be unlocked before accessing the property.

# Instructions
Both **compilation** and **execution** are basics:

### Compilation
To build the project : `make` \
*or build it from new* : `make re`

To remove just object files : `make clean` \
*or remove executable too* : `make fclean`

### Execution
Then your executable **philo** needs four or five arguments, no more, no less. \
For example : `./philo 200 190 50 40 20`, means

- Number of philosophers : 200
- Time to die : 190
- Time to eat : 50
- Time to sleep : 40
- Number of times each philosopher must eat: 20 (optional)

# Resources
Even though most of my ideas come from other students' advice, here are the resources that helped me much through this project.
### Articles
[Dining Philosophers problem. 42 project guide](https://medium.com/@denaelgammal/dining-philosophers-problem-42-project-guide-mandatory-part-a20fb8dc530e) \
[Threads, Mutexes and Concurrent Programming in C](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)

### AI usage
I've mainly used Claude AI to help me understand some algorithmic issues *(especially about the mutexes between threads)*.