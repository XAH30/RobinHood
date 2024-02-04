# RobinHood
Solving collisions in hash tables using the Robin Hood method. This algorithm is a representative of open addressing hashing
# Hashing with open addressing
The open addressing method is one way to solve collisions in hash tables. Instead of creating chains (lists) for elements with the same hash values, the open addressing method proposes to place elements in the table itself, moving them to other positions if collisions occur.
Closed hashing uses a re-hashing technique. If an attempt is made to place element x in a segment number h(x) that is already occupied by another element (collision), the re-hashing technique selects a sequence of other segment numbers h_1 (x), h_2 (x) ,... where element x can be placed. Each of these locations is sequentially checked until a free one is found. If there are no free segments, then, therefore, the table is full and element x cannot be added.

![image](https://github.com/XAH30/RobinHood/assets/73390555/d6f5cf36-f2f3-4c25-ade7-04dfdefca621)

In order to speed up the search there are several algorithms, but we will focus on the Robin Hood algorithm.
# Robin Hood Algorithm
Robin Hood algorithm is a method for solving collisions in hash tables based on the open hashing method, which uses the idea of moving elements from an occupied cell to another free cell.
# Algorithm complexity
The complexity of Robin Hood's algorithm depends on several factors such as the size of the hash table, the number of elements and the degree of collisions.
In the worst case, when all elements are hashed into one cell and it is required to move each element to the next free cell, the complexity of Robin Hood's algorithm can be quadratic - O(n^2), where n is the number of elements in the hash table.
However, in the average case, when collisions are rare and elements are evenly distributed over the hash table, the complexity of Robin Hood's algorithm can be linear  O(n), where n is the number of elements in the hash table.
# Working principle
The principle of the Robin Hood algorithm is that when a collision occurs, the element that is trying to occupy an already occupied cell is moved to another free cell. This avoids long collision chains and improves hash table performance.
# Peculiarities of the algorithm
Insertion logic - if the distance to the ideal position for an element already stored in a slot is less than for a new one, then we "evict" the element from the slot and check further with whom it can be rearranged ("take the position from the rich element and give it to the poor one"). 
To implement the Robin Hood algorithm, we need to define a function that will calculate a new position for an element when a collision occurs, and then move the element to this new position. This process can be repeated several times until a free cell for the element is found.
One disadvantage of Robin Hood's algorithm is that it can lead to longer time to find an item in the hash table as items can be moved original positions. Nevertheless, this method is still widely used due to its effectiveness in solving collisions.
# Robin Hood's hashing algorithm solves several problems:
1. Collision resolution: One of the main tasks of hashing is to resolve collisions - situations where two or more elements receive the same hash code and try to occupy the same cell in the hash table. The Robin Hood algorithm solves this problem by moving elements to the next free cell if the current cell is already occupied.
2. Uniform distribution of elements: The goal of a good hashing algorithm is to ensure that the elements are evenly distributed throughout the hash table. This minimises collisions and improves the performance of search, insertion and deletion operations. Robin Hood algorithm seeks to distribute elements evenly by moving them to the next free cell when collisions occur.
3. Efficiency and performance: Robin Hood algorithm can be an efficient and fast way to solve collisions in hash tables. It provides linear execution time for insertion, search and deletion operations of elements and minimises the number of collisions which can lead to improved performance and efficiency of the algorithm.

Thus, Robin Hood's hashing algorithm solves the problems related to collision resolution, uniform distribution of elements and improving the performance of hash table.

# Graph of dependence of the number of collisions on the table load
![image](https://github.com/XAH30/RobinHood/assets/73390555/1307e897-b93f-4ab8-80f7-7bf531645f37)
# Graph of dependence of insertion time on table size
![image](https://github.com/XAH30/RobinHood/assets/73390555/728f238e-30a8-43b8-a160-e0971de10e85)
# Graph of deletion time dependence on table size
![image](https://github.com/XAH30/RobinHood/assets/73390555/5f91ba63-5ae1-43e1-85ad-d90199aac959)
# Graph of dependence of search time on table size
![image](https://github.com/XAH30/RobinHood/assets/73390555/009ff97c-925d-4e53-8104-ee0f78c3ec83)



