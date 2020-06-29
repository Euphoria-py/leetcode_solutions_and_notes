
# Two Sum
+ Two Sum problem is such a classic problem that appear in almost every online
judging system.

## First solution
+ The first solution is brute force.
+ For every integers in the array, we do a search on the whole array to find
that if there are matched number.
+ The space complexity is O(n^2) and time complexity is O(n).

## Second solution
+ The second solution use map to store <value,index> of array.
+ Since there are exactly one solution. Every time we search a element to see 
if there exists matched number.
+ If not, we put it into map. If it can be matched with another number, when
we search that element, they can be matched.
+ NOTICE: Exactly one solution.
+ The space complexity is O(n)(In fact I didn't consider the complexity of 
creating a map) and the time complexity is O(n).

## Third solution
+ Sort the array.
+ Use double pointers, one for head and the other for end.
+ Use a map to store the indices and value.
+ Considering the complexity of creating a map, the runtime may not be good.
+ Time complexity is O(nlogn) and space complexity is O(n). 


