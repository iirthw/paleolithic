# Pool Data Structure (from Mediatek Tech Exercise)

Malloc is a general purpose memory allocator. It can allocate contiguous blocks of memory of arbitrary size. This flexibility introduces overheads and can often lead to malloc/free being a performance bottleneck. One situation where this commonly occurs is when an algorithm makes use of lots of short-lived objects. An example might be geometry processing, where vertices, edges and faces can be split or merged often.
A common technique to avoid the allocation/deallocation overhead is to create a pool of objects that are allocated ahead of time. As this problem occurs quite commonly it would useful to have a reusable, generic data structure that fulfils the following requirements: 

## Essential requirements:
* The pool should support four key operations:
  - Pool construction.
  - Pool destruction.
  - Object construction - allocate and return an object from the pool. 
  - Object deconstruction - release and return an object to the pool.
* The pool need only support a single type of object.
* The pool should support primitive and POD types.
* The pool should contain at least 1000 objects.
* The pool should be as performant as possible. Ideally, it should outperform malloc/free for 100+ allocs/deallocs.
* The pool should consume as little memory as possible.

### Desirable requirements:
* The pool should contain a user-defined number of objects.
* The pool should support all types:
  - Polymorphic.
  - Multiply inherited.
  - Non-default constructible.
* The pool should be simple and intuitive to use and require the minimal amount of code change to switch between malloc/free/new/delete and the pool.
* The pool should be robust and fail elegantly if:
  - It is full.
  - An attempt is made to deconstruct a null object.
  - An attempt is made to deconstruct a object that does not belong to the pool.

### Bonus requirements:
* The pool should support a theoretically limitless number of objects.

## Considerations:
* Document any assumptions.
* Document the expected storage requirements of the pool.
* Document any trade-offs that were made to reach this target.
* Document the expected algorithmic complexity of the pools operations.
* Document any trade-offs that were made to reach this target.
* Include any tests used to verify the correctness of the pool.
* You are free to use any C language or library feature from the C99 standard.
* You are free to use any C++ language or library feature from the C++11 standard.

## Literature:
*   [Lafferty and Alexandrescu] Modern C++ Design: Generic Programming and Design Patterns Applied 1st Edition, 
    Chapter 4: Small-Object Allocation, 2001