# Add_Two_Numbers

## First
+ The code is my original code. Apparently this is not
a difficulty problem. The time complexity is O(n) and
the space complexity is also O(n).
+ The approach is easy. Scan every digit to the end.
+ Runtime: 56 ms 10.2%
+ Memory Usage: 70.1 MB 74.65%

## Second
+ Then I looked for the discussion and got a post
which claimed beats 100%(in fact 50%).
+ This solution is succinct and clean. I really learn
much.

## Third
+ This solution is long and easy to read.
+ It defeats 97%.
+ It only scan the linkedlist a and b concurrently,
the calculate the sum.
+ For the rest a or b, just calculate and put
it in the result linkedlist.
+ Why it runs so fast? Puzzling.

## Someting I learn
+ To see if a pointer is null.
```c++
class_name * ptr;
if(ptr);  
    ......
if(!ptr);
    ......
```
+ `or` keyword in c++
```c++
while(a==0 or b == 0) {
    ......  
}
```
+ Such value assignment approach is amazing.
```c++
 borrowDig = (nowDig >= 10);
```

+ The null pointer.
```c++
ListNode *head = nullptr;
l1 = (l1 ? l1->next : nullptr);
```

+ Use bracket to initial primitive type.
```c++
int borrowDig(0);
```
