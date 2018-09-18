# GAM200 Week 2 - Tuesday
## Topic: Architecture Lecture

### Prerequisites
1. C Programming
2. C++ Object Oriented Programming

---

## What is Architecture?
It is the **organizational structure of a system**, including its decomposition into parts, their connnectivity, interaction mechanisms, and the guiding principles and decisions that you use in the design of the system.


## Simplicity
- Everything should be made as simple as possible but not simpler.
- The job of the architect is to make all the other programmer's job simplier.
- Do not build complexity for the sake of complexity. It should be understandable at a glance.
- Should allow for fast iterations with minimal refactoring.

Examples of simplifying code are:
- Removing redundancy (File IO, Cross Platform)
- Providing a common interaction system (Messaging system)
- Standardizing certain problem solutions.
     - Using Design Patterns like:
        - Singleton
            - Not the best, but make it work first.
        - Function input parameters
            - Standardize input parameters order or wrap it with a struct
        - STL (Standard Template Library)
            - Don't reinvent the wheel.
  
## Embrace Change
- Do Plan for Change
    - Make it easy to change as other programmers will be working on it too.
- Build your architecture for change
    - Make it extendable and modular.
- Maximize flexibility while mainintaing simplicity
- Data driven functionality. Don't hard-code anything.
- Don't waste time building what may not be needed
- Iteration is key.

## Organize
- Code should be divided into functional atomic pieces.
- Alieies to systems, code files etc.
- However, simplicity and flexiblity are more important.
- Do not organize by what it is but what does it do.

### Data Oriented
- Think of your engine as two things. Data and Processing of Data.
    - Data refers to the current *state* of your game.
        - Transform, Scripts, Game Data are considered data.
        - You want to build an interface that reflects that data.
    - Code transforms sets of data.
    - One class should have one responsibility (Single Responsible Principle)

## Encapsulate variability
- **Program to an abstraction not an implementation**
- Interface is something that you will provide to your users.
- The implementation should be hidden from the user.
    - Team member A should not worry on *how* Team member B build his system.
    - He only need to know how to use the interface.
-  Move the code and responsibility inside abstracted objects.

## Dependencies
- Dependencies can be code, headers, libraries and even people.
- A Good Architect strives to reduce as much dependecies as possible by
    - Splitting systems, splitting files and even projects.
- Minimize using any Global variables.
    - Note: Minimize does not mean eliminate, if there is a strong need then go ahead.
- Good libraries can help by moving responsibility to specialists and leveraging broadly used code.
- Strives for loose coupling between all objects.

## High level
- Game engine consists of systems.
- Each system is in charage of a single aspect of the game:
    - Graphics
    - Physics
    - Logic (Gameplay)
    - Etc.
- Every frame, each system will be updated.
- A System manager should be overseeing this systems.
    - The system manager needs to control the life-time of this systems as well as to destroy them at the end.
    - Also controls the sequence of those systems like:
        - Creation of systems.
        - Updating of systems. Eg. Input before Physics.
        - Destruction of systems.

How do this systems communicate and share data? It is through the use of GameObjects.

## Game Objects
- Pieces of logical interactive content
- Have data that all systems need.
- GameObjects contain data, systems work on gameobjects.
    - How to build game objects?
        - Start with basic object oriented principles.
        - Base class is GameObject
        - Any specialization will derive from GameObject
- Main idea is that Calling code uses the Interface
- Objects implements the interface.

## Abstraction
- Calling code can treat all objects with the same abstraction as if they are the same.
- Calling code now relies on an abstraction and the implementation relies on said abstraction.

## IS-A vs HAS-A (Composition vs Aggregation)
- Am I a feature? or do I own a feature.
- It is important to determine what is a IS-A or whether a HAS-A is more suitable.
- Eg. A Rifle-man is a Man but he HAS-A Weapon.
    - Sometimes a Rifle-man can be a Sniper for example, if he changes his weapon as such.
- You should always prefer composition over aggregration.
    - Factors that matter are as such:
        - The life-time of objects.
            - The rifle-man can die but the rifle can still be dropped and picked.
                - Separate life-time. **Composition** is preferred here.
        - The relationship of objects.
            - Whenever a car is destroyed, the engine is destroyed along with it.
                - Linked life-time. **Aggregration** is preferred here.
- Aggregation
    - Object reference different objects
    - Not necessarily lifetime bound
    - Multiple object may reference the same aggregtated object.
- Composition
    - Object owns different objects called components.
    - Components do not exisit outside of composition.
    - When composition is destroyed so are components.
    - Each component has only one owner.
- **Always Prefer aggregation and composition to inheritance**






