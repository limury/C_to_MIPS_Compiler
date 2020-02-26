Management Review
============================================
As I(Darrick) was primarily in charge of documentation and timekeeping on this project, this review is written from a first-person perspective, speaking for the both of us. 

The effort log contains a brief summary of each work session, mainly noting what was accomplished in the day. We did not find it particularly meaningful to keep track of work done in hours, and preferred a 1-5 difficulty scale.

The milestone log shows the workplan put in motion since the beginning, with clear goals outlined and a weekly period assigned to each milestone to give it a deadline.

Division of Labour
-------------
Having worked together before, we already knew how this project was going to pan out. Olly focused on the technical aspects of the project, having gone through the exercises over the summer and already having made a headstart on the lexer before any work was scheduled to begin. Throughout the development process, I saw it as my role to plan our timeline, keep track of our progress and serve as a second opinion during problem solving processes. A typical start to every session would be for us to update each other on where we stood. The order of things discussed was often as below:

* Darrick: Begins the session by bringing up the timeline and checking how much time was left for the current milestone
* Olly: Explains where we are in the code and what was set to be done that day
* Olly: Outlines the major problems to be solved in the day, and discusses how we could fix them
* Darrick: Irons out how we could split the day's work to be finished faster

The verbal meeting would typically end here and we would return to our own spaces to code, reconvening either to solve a newfound problem or discrepancy. 

Critical Decisions
---------------------------
The feature list, as written in the readme, was decided before the completion of the project. We ranked them from easiest to most difficult, and decided that the most tedious task was to implement support for types other than int. Doubles and floats required completely different arithmetic operations due to their size taking up two registers, making them not worth the time and effort for the gain in marks. There was potentially time to implement chars and unsigned ints, but again, the effort of adding clauses in every arithmetic, logical and assignment operation was not worth the mark gain that it would yield over taking that same time to catch up on other lectures and score higher in an exam that weighed much more than this project.

In an ideal world, we would have liked to try our hand at an optimised compiler using the techniques taught in the lecture, but it was better (from the perspectives of time efficiency and program correctness) to implement using a push-to-stack model where any operation/instruction would save the registers it was about to use to the stack to prevent loss of data.

Time Management
-------------
This was the most critical task for both of us, considering the concurrency of other deadlines such as the Numerical Analysis coursework and blackboard tests. We first began by deciding what features we wanted in the minimal version of a compiler we would consider submittable. The dates set out in milestones.csv were then made as a conservative estimate to achieve that goal of the submittable compiler. Even with conservative estimates, Codegen turned out to take exceptionally long as even after the first prototype was achieved, lots of little bugs were found during the testing which required either patch-style fixes or entire restructures of some parts of the program. This was quite prevalent in our previous projects and thus was proactively controlled by compartmentalising the different functions of the compiler into the context file, which allowed for easy addition of new functions or debugging of old ones.

Overall the project finished quite smoothly and we had a submittable version 5 days ahead of the deadline, giving us a buffer to find trivial bugs and remove them at our leisure up until the submission date.
