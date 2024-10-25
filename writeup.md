# PA2 Write Up

## Design Decisions
I I calculated my Index Page capacity as capacity = (page_size - header)/(*keys + children) - 1, the 1 is because the children have one more capacity than keys. And after inserting keys, I sorted the keys again. The process is similar to Leaf page. The important point for leaf page is to define the data size, so I used malloc to define, and uses serialize and deserialize to save data.

## missing elements
the bTree functions, I filled in some codes but has not finished it. 

## Time spent on this assignment
Approximately 10 hours.

## Difficulty and Confusion
I found it hard to understand the connection with BTree and Index Page and Leaf Page. 
