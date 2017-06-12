###############################################################
# Program:
#     Week 09, Binary Search Tree
#     Brother JonesL, CS265
# Author:
#     Nathan Bench, Jed Billman, Jeremy Chandler, Justin Chandler
# Summary:
#     Implementation of the Binary Search Tree with a Binary Sort
# Time:
#     Nathan Bench:
#     Jed Billman:
#     Jeremy Chandler:
#     Justin Chandler:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week09.o
	g++ -o a.out week09.o -g
	tar -cf week09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week09.o     : the driver program
##############################################################
week09.o: bnode.h bst.h stack.h week09.cpp sortBinary.h
	g++ -c week09.cpp -g

