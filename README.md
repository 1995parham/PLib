# PLib
## Introduction
Parham Personal C Library :) written just for fun ... This library contains
useful functions and data structure.
## PString
### Functions
#### Tokenizer
This function parsed `src` with `token` and return size of result form function
and fill result with null terminated string. this function allocated space
for result in result passed into function by it self.
```c
int plib_string_tokenizer(const char *source, const char *token,
	char ***result);
```
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
