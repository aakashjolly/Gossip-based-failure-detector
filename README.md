# Gossip-based-failure-detector
Gossip-based failure detector with dissemination in C++ using Emulnet for emultating network

The base template code is taken from https://www.coursera.org/learn/cloud-computing/ course taught on Coursera by Prof. Indranil Gupta at UIUC.

Task was to implement either Gossip-based or SWIM style failure detector which was both failure detector mechanism and knowledge dissemination.
I implemented Gossip-based following A gossip-style failure detection service(https://dl.acm.org/citation.cfm?id=1659238) paper.

Test cases create 10 nodes at varying times and have different scenarios like one node failing, multi-node or high message drops. Grader.sh checks 
the correctness(failure is detected by atleast one non-failed node) and accuracy(accuracy of node being actually failed and not false signal).

The network is Emulated using Emulnet.cpp and Emulnet.h but can easily be replaced with real-world code. Original template code provided can be downloaded from - 
https://spark- public.s3.amazonaws.com/cloudcomputing/assignments/mp1/mp1.zip

To run 

make && ./Grader.sh

For running single testcase - 

./Application testcases/example

Every node sends to log(n) neighbors in it's own membership list. Thus network load is - Heartbeat rate * n(number of nodes) * O(n) (membership list) * log(n)
= Beta(n^2logn)
