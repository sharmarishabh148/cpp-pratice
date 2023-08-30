Easy Problems -

1. Reverse Linked List
2. Unique Email Addresses
3. Merge Two Sorted Lists
4. Diameter of Binary Tree
5. Best Time to Buy and Sell Stock
6. Happy Number
7. Intersection of Two Linked Lists
8. Climbing Stairs
9. Two Sum
10. Palindrome Linked List
11. Maximum Product of Three Numbers
12. Valid Parentheses

Medium Problems -

1. Subdomain Visit Count
2. Max Area of Island
3. Generate Parentheses
4. Delete Nodes And Return Forest
5. Number of Distinct Substrings in a String
6. Two Sum II - Input Array Is Sorted
7. Populating Next Right Pointers in Each Node
8. Design Tic-Tac-Toe
9. Lowest Common Ancestor of a Binary Tree
10. Decode String
11. Valid Sudoku
12. My Calendar I
13. Letter Combinations of a Phone Number
14. Number of Islands
15. Container With Most Water
16. Reorganize String
17. Boats to Save People
18. Rotting Oranges
19. Maximum Length of Repeated Subarray
20. 3Sum Smaller
21. Meeting Rooms II
22. Design Circular Queue
23. Course Schedule II
24. Partition Equal Subset Sum
25. Merge Intervals
26. Course Schedule
27. Spiral Matrix
28. Find First and Last Position of Element in Sorted Array
29. Coin Change
30. LRU Cache
31. Word Search
32. Unique Paths II
33. Search in Rotated Sorted Array
34. Interleaving String
35. Longest Substring Without Repeating Characters
36. 3Sum

Hard Problems -

1. Employee Free Time
2. Trapping Rain Water
3. Basic Calculator IV
4. Sudoku Solver
5. Reverse Nodes in k-Group
5. Find Median from Data Stream
6. Reconstruct Itinerary
7. Get the Maximum Score
8. Text Justification
9. Maximum Total Beauty of the Gardens
10. Wildcard Matching
11. Partition Array Into Two Arrays to Minimize Sum Difference



Can you build a Loadbalancer on your own? Ofcourse yes. Should you use it in production - Umm - Maybe not!

Here's an interesting blog which teaches how to build your own load balancer using golang: https://lnkd.in/dbcPah_w
Source code: https://lnkd.in/dsh2BUBw



Why JSON Web Tokens is not recommended for authentication
especially in Golang?

It was an Golang interview questions and I was like "its not?"

long story short I didn't get the job

So here is why JWT is not recommended 

1. It provides pretty of algorithms true! but some are vulnerable - meaning developers can easily choose the vulnerable ones like RSA
 - RSA with PKCSv1.5 is susceptible to a padding oracle attack.
 - Or ECDSA can face an invalid-curve attack

2. Trivial Forgery
- One bad thing about JWT is that it includes the signing algorithm in the token header.
- Because of this, we have seen in the past, an attacker can just set the alg header to none to bypass the signature verification process.

So what should we use?
 
We need to work with tokens thats for sure!

so we need an alternative to Json Web tokens and that is PASETO

PASETO is better than Json Web Tokens given it is Platform Agnostic Security Token which solves issues that have being highlighted with Json web tokens.

It solves all issues of JSON web token by first, provide strong signing algorithms out of the box.

for more information you should check out this tutorial https://lnkd.in/dwFNsTfh
by TECH SCHOOL

the image below shows a simple authentication



Are maps safe to work with in concurrency program in golang?

NO!( common interview question) but that doesn't necessary mean they are invalid in go routines!

Because packaging a map into a struct that has embedded mutex can be used safely in a concurrent program.

We all know that http server -- listen and serve works concurrently to serve traffic directed to it and as such, used such case to present how we can use maps in concurrent program.

I used maps as database to host my data while interacting with the program.

