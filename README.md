# LinkedListC
C Linked List library
this is my first try at programming C, and as such this will not be open to commits. if you like this library you can of course use it, and feel free to send me any challenges to implement that you find interesting!

this library implements the Node struct, and the Linked List struct.
# Available Commands:

Node* get_to_end:
returns pointer to last node in a list.

Node* get_to_index:
return pointer to node at index
note: index 0 is the head.

void add_to_start:
adds a node to the start of the list.

void add_to_end:
adds a node to the end of the list.

void add_at_index:
adds a node at the index specified.
note: adding at index 0 is equivalent to add_to_start, and adding at index (Len-1) is equivalent to add_to_end.

void remove_from_list:
removes node at index, and frees the memory.

int get_len_list:
returns length of the list.

void print_list:
prints the list in a nice looking manner, like; [1, 2, 3]

LinkedList merge:
merges two sorted lists into a third, sorted one.


