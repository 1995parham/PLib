# PLib
## Introduction
Parham Personal C Library :) written just for fun ... This library contains
useful functions and data structure.
## PStack
### Types and Values
#### struct PNode
```c
struct PNode {
	void *data;
	struct PNode *next;
};
```
The PNode struct is used for each element in
the stack.
#### struct PStack
```c
struct PStack {
	struct PNode *head;
	size_t size;
};
```
The PStack struct is used for stack metadata.
