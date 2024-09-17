# Singly-Linked-List

Own implementation of a singly linked list, which has the following operations defined:
1. Basic list operations: constructing, inserting elements at the beginning of the list, iterating over the list, size of the list, removing elements.
2. Move operations (Move constructor, move assignment)
3. The method for inserting elements at the beginning must have an overload for an rvalue reference, and move objects correctly.
4. Constructing a list using a constructor that takes a std::initializer_list.
5. The list must be templated, and work not only with primitive values, but also with objects (and correctly release them)
6. Ideally, you should strive for a class interface like std::forward_list [1], but you do not need to implement absolutely all methods - a custom allocator, and emplace_* methods are not required (But it will not be a minus). sort, merge, unique do not need to be done.
7. Implement the split_when method, which allows you to split a list into two, which determines the position from which element to split, based on the bool value returned from the passed predicate function [2]. Pass predicate for example as std::function
