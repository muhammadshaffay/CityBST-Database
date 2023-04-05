# CityBST-Database
A scalable and efficient program to store and manage a city database with search and range query operations.

Available Operations: insert, delete, search, and range query.

Implemented a city database using a BST to store the database records of 40,000+ cities. Each database record contains the name of the city (a string of arbitrary length) ,the coordinates of the city expressed as integer x- and y- coordinates (longitude and latitude) and the population of the city. The BST is organized by city name.

Database allows records to be inserted , deleted by name or coordinate, and searched by name or coordinate. Another operation that is supported is to print all records within a given distance of a specified point. A recursive function named PrintRange is also available, given the pointer to the root of BST, a low-key value and a high key value, prints in sorted order all records whose key values fall between the two given keys. Here the key value is the population of the city. 

Another recursive function SmallCount that, given a pointer to the root of the BST and a key K (population), returns the number of cities having population less than or equal to K. Function small count visits as few nodes in the BST as possible.
