/*
 * possible number of triangles
 * get all the possible sub arrays of 3 elements and check the following condition:
 *      a + b < c
 *      b + c < a
 *      a + c < b
 * finding the possible subarrays with 3 elements will take nC3 time and checking for conditions would take constant time
 * so overall time would become O(n^3)
 * */
