
**(A) Which underlying data structure (*array* or *linked-list*) will you use as a basis to model the flight plan? In two–three sentences, justify your answer.**

A flight plan needs to be able to able to hold any number of waypoints, with no fixed size or limit, in a specified, fixed ordering. Therefore, an array would be inappropriate, as its length must be defined statically at compile-time. A linked list would be a better solution, as it has a variable size.

**(B) Which kind of abstract data type (*binary tree, general tree, array, stack, priority queue, double-ended queue, set, list, etc.*) would you use to model the flight plan? In two – three sentences, justify your answer by indicating the functionality required.**

A flight plan needs to have a variable length - hold as few or as many elements as necessary, have a movable pointer which can refer to different waypoints on the plan, be able to insert and remove elements after the current pointer location, be traversable in at least a forwards direction, and be reversible. As such, tree data types would be inappropriate, as there is no need for multiple children, and stacks and queues have a fixed in/out restrictions that would not be desirable in our need for a movable pointer. Therefore, a simple list data structure with the addition of a pointer variable to keep track of the current position would be the best solution to model the flight plan.
